//Bucket Sort 

//Time Complexity Best O(n+k) worst O(n^2)
//Create an array bucket and calculate every element bucketIndex to store element in their respective buckets 
//Sort Sort individual buckets  sort(buckets[i].begin(), buckets[i].end()); and concatenate the array 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void BucketSort(float arr[], int n) {
    vector<vector<int> > buckets(n);
    for(int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    float arr[n];
    cout << "Enter the elements in the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    BucketSort(arr, n);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

