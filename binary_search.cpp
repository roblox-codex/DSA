#include <iostream>
using namespace std;

// Function for binary search
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // element not found
}

// Driver code
int main() {
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the element to be searched: ";
    cin >> x;
    int result = binarySearch(arr, n, x);
    if (result == -1)
        cout << "Element not found";
    else
        cout << "Element found at index " << result;
    return 0;
}
