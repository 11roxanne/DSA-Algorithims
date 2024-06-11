//Insertion Sort 
//Time Complexity Best- O(n) Worst & Average- O(n^2)

//In selection sort we considered the first element as sorted and other elemeny unsorted which are comapred and shifted.
// for (int i = 1; i < n; i++) we start from the second element 
// while (j > 0 && arr[j - 1] > arr[j]) compare and swap elements and reduce the value of j.

#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {  
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
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
    
    InsertionSort(arr, n);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

