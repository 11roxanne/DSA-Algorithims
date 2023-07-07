#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int i, j;
    char str1[100];
    char str2[100];

    cout << "Enter the word: ";
    cin.getline(str1, 100);

    int length = strlen(str1);
    cout << "The length of the string is: " << length << endl;

    for (i = 0; str1[i] != '\0'; i++) {
        // i is at the end of the string now
    }
    i = i - 1; // Adjust i to the last valid index of the string

    for (j = 0; i >= 0; j++, i--) {
        str2[j] = str1[i];
    }
    str2[j] = '\0'; // Add null character at the end of str2

    cout << "Reverse of " << str1 << " is: " << str2 << endl;

    return 0;
}


/*
int main()
{
	int i , j , temp;
	char str[100];
	cout<<"Enter the word:";
	cin.getline(str1 , 100);
	
	for(i=0; str[i]=!'/0'; i++){    //i is at the end of the string now
	}
	i=i-1;
	
	for(j=0; j<i; j++){   //j is at the starting of the string 
		temp=A[i];
		A[i]=A[j];
		A[j]=temp;
		
	}
	cout<<"Reversed string is :"<<Str;
	retun 0;
	

}
*/
