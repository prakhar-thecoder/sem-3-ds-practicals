#include <bits/stdc++.h>
using namespace std;

int interpolationSearch(vector<int>& arr, int key) {
    int low = 0, high = arr.size() - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {10, 12, 15, 18, 20, 22, 25, 30, 35, 40};
    int key = 22;

    int index = interpolationSearch(arr, key);

    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array." << endl;
    }

    return 0;
}
