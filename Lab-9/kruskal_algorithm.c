#include <iostream>
#include <algorithm>
using namespace std;

const int V = 6;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

void KruskalMST(int graph[V][V]) {
    Edge edges[V * V];
    int e = 0;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j])
                edges[e++] = {i, j, graph[i][j]};
        }
    }

    sort(edges, edges + e, compareEdges);

    Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    Edge result[V];
    int i = 0, count = 0;
    while (count < V - 1 && i < e) {
        Edge next = edges[i++];
        int x = find(subsets, next.src);
        int y = find(subsets, next.dest);
        if (x != y) {
            result[count++] = next;
            Union(subsets, x, y);
        }
    }

    cout << "Edge \tWeight\n";
    for (int j = 0; j < count; j++)
        cout << result[j].src + 1 << " - " << result[j].dest + 1 << " \t" << result[j].weight << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 4, 0},
        {2, 0, 3, 3, 0, 7},
        {0, 3, 0, 5, 0, 8},
        {1, 3, 5, 0, 9, 0},
        {4, 0, 0, 9, 0, 0},
        {0, 7, 8, 0, 0, 0}
    };
    KruskalMST(graph);
    return 0;
}
