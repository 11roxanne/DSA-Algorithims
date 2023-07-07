#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100];
    char str2[100];
    int i, j;
    int word;
    cout << "Enter the string: ";
    cin.getline(str1, 100);

    for (i = 0; str1[i] != '\0'; i++) {
    }
    i = i - 1;

    for (j = 0; i >= 0; j++, i--) {
        str2[j] = str1[i];
    }
    str2[j] = '\0';

    if (strcmp(str1, str2) == 0) { // Used strcmp() to compare two strings
        cout << "The word is a palindrome." << endl;
    } else {
        cout << "The word is not a palindrome." << endl;
    }

    return 0;
}

