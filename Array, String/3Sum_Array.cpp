#include<iostream>
using namespace std;

int main()
{

	int n;
	cout<<"Enter the size of array:";
	cin>>n;
	int A[n];
	cout<<"Enter the elements:";
	for(int i=0; i<n; i++)
	{
		cin>>A[i];
		
	}

	//to check whether any triplets are there whose sum is zero
	bool found= false;
	for(int i=0 ; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			for(int k=j+1; j<n; j++){
				if(A[i]+A[j]+A[k]==0){
					cout<<A[i]<<""<<A[j]<<""<<A[k]<<"Triplet found";
					found= true;
				}
			}
		}
	}
	if(found==false){
		cout<<"No triplet found";
	}
	
	return 0;
	
	
}
