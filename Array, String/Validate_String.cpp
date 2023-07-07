#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int str[100];
	int i, j;
	cout<<"Enter the string";
	cin.getline(str, 100);
	
	for(i=0; str[i]=!'/0'; i++){
		
		if((str[i]>"a" && str[i]<"z") && (str[i]>"A" && str[i]<"Z") && (str[i]>"0" && str[i]<"9"))
		{
			cout<<"The string valid";
		}
		else{
			cout<<"The string is not valid:";
		}
	}
	return 0;
	
}

