#include <iostream>
#include <climits>
using namespace std;

#define V 5

struct MinHeapNode { int vertex; int dist; };
struct MinHeap { int size; int capacity; int *pos; MinHeapNode **array; };

MinHeapNode* newMinHeapNode(int v, int dist) {
    MinHeapNode* node = new MinHeapNode;
    node->vertex = v; node->dist = dist;
    return node;
}

MinHeap* createMinHeap(int capacity) {
    MinHeap* h = new MinHeap;
    h->pos = new int[capacity];
    h->size = 0;
    h->capacity = capacity;
    h->array = new MinHeapNode*[capacity];
    return h;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a; *a = *b; *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->dist < minHeap->array[smallest]->dist)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->dist < minHeap->array[smallest]->dist)
        smallest = right;
    if (smallest != idx) {
        MinHeapNode* smallestNode = minHeap->array[smallest];
        MinHeapNode* idxNode = minHeap->array[idx];
        minHeap->pos[smallestNode->vertex] = idx;
        minHeap->pos[idxNode->vertex] = smallest;
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

MinHeap* build_heap(int distArr[], int n) {
    MinHeap* minHeap = createMinHeap(n);
    for (int v = 0; v < n; ++v) {
        minHeap->array[v] = newMinHeapNode(v, distArr[v]);
        minHeap->pos[v] = v;
    }
    minHeap->size = n;
    for (int i = (minHeap->size / 2) - 1; i >= 0; --i) minHeapify(minHeap, i);
    return minHeap;
}

MinHeapNode* extract_min(MinHeap* minHeap) {
    if (minHeap->size == 0) return NULL;
    MinHeapNode* root = minHeap->array[0];
    MinHeapNode* last = minHeap->array[minHeap->size - 1];
    minHeap->array[0] = last;
    minHeap->pos[root->vertex] = minHeap->size - 1;
    minHeap->pos[last->vertex] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}

void decrease_key(MinHeap* minHeap, int v, int dist) {
    int i = minHeap->pos[v];
    minHeap->array[i]->dist = dist;
    while (i > 0 && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) {
        minHeap->pos[minHeap->array[i]->vertex] = (i - 1) / 2;
        minHeap->pos[minHeap->array[(i - 1) / 2]->vertex] = i;
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

bool isInMinHeap(MinHeap* minHeap, int v) {
    return minHeap->pos[v] < minHeap->size;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    for (int i = 0; i < V; ++i) dist[i] = INT_MAX;
    dist[src] = 0;
    MinHeap* minHeap = build_heap(dist, V);
    while (minHeap->size != 0) {
        MinHeapNode* minNode = extract_min(minHeap);
        if (!minNode) break;
        int u = minNode->vertex;
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decrease_key(minHeap, v, dist[v]);
            }
        }
    }
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; ++i) cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 9, 6, 5, 3},
        {9, 0, 2, 0, 0},
        {6, 2, 0, 4, 2},
        {5, 0, 4, 0, 4},
        {3, 0, 2, 4, 0}
    };
    dijkstra(graph, 0);
    return 0;
}
