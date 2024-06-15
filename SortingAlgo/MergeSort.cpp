//Merge Sort

//Time Complexity 0(nlogn)
//Divide the array into smaller sub-arrays until each sub-array contains a single element.
//Merge the sub-arrays back together in sorted order by comparing the elements.

#include <iostream>
using namespace std;

void Merge(int arr[], int l, int r, int m) {
    int n = r - l + 1;  // Size of the temporary array
    int temp[n];  // Temporary array 

    int i = l;    // Pointer at first element of left sub-array
    int j = m + 1;  // Pointer at first element of right sub-array
    int k = 0;    // Pointer at first element of temporary array 

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {  // if first element of left subarray is smaller than first element of right subarray
            temp[k] = arr[i];    // then store it in the temporary array
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy rest of the elements in the temporary array 
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy sorted elements back to the original array
    for (int i = l, k = 0; i <= r; i++, k++) {
        arr[i] = temp[k];
    }
}

void MergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, r, m);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    MergeSort(arr, 0, n - 1);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
