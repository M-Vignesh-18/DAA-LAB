#include <iostream>
using namespace std;
int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter target: ";
    cin >> key;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            cout << "Found at index " << mid;
            return 0;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Not found";
}
