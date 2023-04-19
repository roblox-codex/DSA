#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Found x at index i
        }
    }
    return -1; // x not found in array
}

int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the element to search for: ";
    cin >> x;
    int result = linearSearch(arr, n, x);
    if (result == -1) {
        cout << "Element not found in array\n";
    } else {
        cout << "Element found at index " << result << endl;
    }
    return 0;
}
