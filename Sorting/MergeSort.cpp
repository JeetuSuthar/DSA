#include <iostream>
#include <vector>

using namespace std;

// Merge function to merge two halves of the array
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Length of the left subarray
    int n2 = right - mid;     // Length of the right subarray

    vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temp arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr[left..right]
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Recursive function to implement Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // Find the middle point

        // Recursively sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10}; // Example array

    cout << "Original array: ";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1); // Call mergeSort on the entire array

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
