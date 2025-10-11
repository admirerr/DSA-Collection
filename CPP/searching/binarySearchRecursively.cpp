#include <iostream>
using namespace std;
int binarySearch(int a[],int i,int j,int x)
{
	// i=leftend, j=rightend, mid=midpoint
	//	(point of search interval)
	int mid;
	if(i<=j) //check every index of array
	{
		mid=(i+j)/2; //split array into two sublist
		if(a[mid]==x) //check every element of array
			return mid+1;

		else if(a[mid]<x) //leftend changes in search interval
			return binarySearch(a,mid+1,j,x);
		
		else	//rightend changes in search interval
			return binarySearch(a,i,mid-1,x);
	}
	return -1; //if not found, location=-1;
}
int main()
{
	int a[]={1,5,8,9,12,13,17,19};
	int size=sizeof(a)/sizeof(int); //size of array
	cout<<"Array elements are:"<<endl;
	for (int i = 0; i < size; ++i)
	{
		cout<<a[i]<<endl;
	}
	int item;
	cout<<endl<<"Enter search item: ";
	cin>>item;
	int loc=binarySearch(a,0,size-1,item);
	//arguments are array,array_initial_size,array_last_size,search_value
	if(loc!=-1)
		cout<<endl<<"Search found. Location="<<loc;
	else
		cout<<endl<<"Search not found.";
	cout<<endl;
	system("pause");
	return 0;
}