//QuickSort 

//Time complexity Best & Average - O(nlogn) Worst - O(n^2)
//divide-and-conquer algorithm that selects a pivot, partitions the array into elements less than and greater than the pivot, and recursively sorts the sub-arrays.

#include <iostream>
using namespace std;

int Partition(int arr[], int s, int e) {
    int pivot = arr[e];  // Last element as pivot
    int pIndex = s;

    for (int i = s; i < e; i++) {
        if (arr[i] <= pivot) {  
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[e]);
    return pIndex;
}

void QuickSort(int arr[], int s, int e) {
    if (s < e) {
        int p = Partition(arr, s, e);
        QuickSort(arr, s, p - 1);
        QuickSort(arr, p + 1, e);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];  
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    QuickSort(arr, 0, n - 1);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  
    return 0;
}

