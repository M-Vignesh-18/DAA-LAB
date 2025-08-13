 #include <iostream>
 using namespace std;
int main() {
    int n, key;
    cout<<"Enter size of an array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
	cout<<"Enter element: ";
	cin >> arr[i];	
	}
	cout<<"Enter target element: ";
	cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i;
            return 0;
        }
    }
    cout << "Not found";
}
