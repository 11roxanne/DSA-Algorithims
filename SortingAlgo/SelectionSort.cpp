//Selection Sort 
//Time Complexity Best, Worst & Average- O(n^2)

//In selection sort we find the smallest element and swap its position with first element 

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minele = i; 
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minele]) {
                minele = j; 
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minele];
        arr[minele] = arr[i];
        arr[i] = temp;
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
    
    SelectionSort(arr, n);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
