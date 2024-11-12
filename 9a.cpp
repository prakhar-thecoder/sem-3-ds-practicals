#include <bits/stdc++.h>
using namespace std;

int binarySearchDescending(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }

        if (arr[mid] < key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {20, 18, 16, 14, 12, 10, 8, 6, 4, 2};
    int key = 12;

    int index = binarySearchDescending(arr, key);

    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
