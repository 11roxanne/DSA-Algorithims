#include <iostream>
using namespace std;

int main()
{
	int *p= new int[5];
	int *q= new int[10];
	
	p[0]=2; p[1]=3; p[2]=7; p[3]=9; p[4]=10;
	for(int i=0;i<5;i++)
	{
		q[i]=p[i];
	}
	delete(p);
	q=p;
	q=NULL;
	
	for(int i=0; i<5; i++){
		cout<<p[i];
	}
	return 0;
}
