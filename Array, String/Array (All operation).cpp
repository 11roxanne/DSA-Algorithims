#include <iostream>
using namespace std;

struct Array {
private:
    int* A;
    int size;
    int length;

public:
    Array() {
        A = NULL;
        size = 0;
        length = 0;
    }

    void create();
    void display();
    void add(int data);
    void insert(int index, int data);
    void remove(int index);
    int linearSearch(int data);
    int binarySearch(int data);
    void reverseArray();
    int sum();
    
};

void Array::create() {
    cout << "Enter the number of elements in the array: ";
    cin >> size;
    A = new int[size];
    length = 0;
}

void Array::display() {
    if (length == 0) {
        cout << "Array is empty." << endl;
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < length; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::add(int data) {
    if (length == size) {
        cout << "Array is full. Cannot add more elements." << endl;
        return;
    }

    A[length] = data;
    length++;
}

void Array::insert(int index, int data) {
    if (index < 0 || index > length) {
        cout << "Invalid index! Insertion failed." << endl;
        return;
    }

    if (length == size) {
        cout << "Array is full. Cannot insert more elements." << endl;
        return;
    }

    for (int i = length; i > index; i--) {
        A[i] = A[i - 1];
    }

    A[index] = data;
    length++;
}

void Array::remove(int index) {
    if (index < 0 || index >= length) {
        cout << "Invalid index! Deletion failed." << endl;
        return;
    }

    for (int i = index; i < length - 1; i++) {
        A[i] = A[i + 1];
    }

    length--;
}

int Array::linearSearch(int data) {
    for (int i = 0; i < length; i++) {
        if (A[i] == data) {
            return i;
        }
    }

    return -1;  // Element not found
}

int Array::binarySearch(int data) {
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (A[mid] == data) {
            return mid;
        } else if (data < A[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;  // Element not found
}
void Array::reverseArray() {
    int temp;
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}

int Array::sum(){
	int sum=0;
	for(int i=0; i<length; i++){
		sum=+A[i];	
	}
	return sum;
}

int main() {
    int ch, data, index;
    int data1, data2;
    Array arr;

    while (1) {
        cout << "\n\nMenu\n";
        cout << "0. Create\n";
        cout << "1. Add\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search\n";
        cout << "6. Reverse Array\n";
        cout << "7. Sum\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 0:
                arr.create();
                arr.display();
                break;

            case 1:
                cout << "Enter the element: ";
                cin >> data;
                arr.add(data);
                arr.display();
                break;

            case 2:
                cout << "Enter the index at which you want to insert: ";
                cin >> index;
                cout << "Enter the element: ";
                cin >> data;
                arr.insert(index, data);
                arr.display();
                break;

            case 3:
                cout << "Enter the index of the element to delete: ";
                cin >> index;
                arr.remove(index);
                arr.display();
                break;

            case 4:
                cout << "Enter the element you want to search: ";
                cin >> data;
                index = arr.linearSearch(data);
                if (index != -1) {
                    cout << "Element found at index " << index << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;

            case 5:
                cout << "Enter the element you want to search: ";
                cin >> data;
                index = arr.binarySearch(data);
                if (index != -1) {
                    cout << "Element found at index " << index << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
                
            case 6:
            	arr.reverseArray();
            	break; 
            
            case 7:
            	break;
            
            case 8:
            	arr.sum();
            	break; 
            	
            case 10:
                cout << "Exiting the program..." << endl;
                exit(0);

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}


