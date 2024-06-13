//Total 7 Patterns 


#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Enter the number:";
	cin>>n;
	
	//Patern 1- To print * half-pyramid
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cout<<"*";
		}
		cout<<endl;
	} 
	cout<<endl;
	
	//Pattern 2- Inverted * half-pyramid
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n-i; j++){
				cout<<"*";
			}
			cout<<endl;
	}
	cout<<endl;
	 
	//Pattern 3- To print number half-pyramid 
	for(int i=0; i<n; i++){
		for(int j=0; j<=i; j++){
			cout<<i+1<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//Pattern 4 - Complete * Triangle 
	for(int i=1; i<=n; i++){
		for(int k=n-i; k>0; k--){  //This loop will add the spaces
			cout<<" ";
		}
		for(int j=1; j<=i; j++){  //This loop will add the * 
			cout<<"* "; 	
		}
		cout<<endl;
		
	}
	cout<<endl;
	
	//Pattern 5 - Inverted Complete * Triangle 
	for(int i=n; i>=1; i--){
		for(int k=n-i; k>0; k--){  //This loop will add the spaces
			cout<<" ";
		}
		for(int j=i; j>0; j--){  //This loop will add the * 
			cout<<"* "; 	
		}
		
		cout<<endl;
		
	}
	cout<<endl;
	
	//Pattern 6- Floyd's triangle, we need to print numbers, but it is also required to increase the number by 1 each time we print it.
	int rows;
	cout<<"Enter the rows: ";
	cin>>rows; 
	int count=1;
	for(int i=1; i<=rows; i++){
		for(int j=1; j<=i; j++){
			cout<<count++<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	
	//Pattern 7- Rectangle
	int n1, n2;
	cout<<"Enter rows:";
	cin>>n1;
	cout<<"Enter columns:";
	cin>>n2;
	
	for(int i=0; i<=n1; i++){
		for(int j=0; j<=n2; j++){
			cout<<"*";
		}
		cout<<endl;
	}
	cout<<endl;
	
	
	
	return 0;
}

