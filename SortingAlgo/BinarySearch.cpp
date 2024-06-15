//Binary Seach 
//Time Complexity Best- O(1) Worst & Average- O(n logn )
//In binary search, the array must always be sorted

#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int target) {
    int left=0;
    int right=n-1;
    
    while(left<=right){
    	int mid=(left+right)/2;
    	
    	if(mid==target){
    		return mid;
		}
		if(mid < target){    //if target is greater than mid , we move towards right halve.
			mid=left+1;
		}
		else{
			mid=right-1;     //if target is smaller than mid , we move towards left halve.
		}
	}
	return -1;
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
    int target;
    cout<<"Enter the element you want to search:"<<endl;
    cin>>target;
    
    
    int result= BinarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element found at index " << result <<endl;
    } else {
        cout << "Element not found in the array" <<endl;
    }

    return 0;
}
