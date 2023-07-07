#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100]; 
    int i, j;
    int word = 0; 
    cout << "Enter the string: ";
    cin.getline(str, 100);

    for (i = 0; str[i] != '\0'; i++) { 
        
    }
    i = i - 1; // Decrementing i by 1 to get the last index of the string

    for (j = 0; j < i; j++) {
        if (str[i] == str[j]) {
            word++; 
        }
    }

    cout << "Number of duplicates in the string is: " << word << endl;
    return 0;
}

