/*	Algorithm of binary search....
procedure binary search (x: integer, a1, a2, . . . , an: increasing integers)
i := 1{i is left endpoint of search interval}
j := n {j is right endpoint of search interval}
while i < j
m : ⌊(i + j)/2⌋
if x > am then i := m + 1
else j := m
if x = ai then location := i
else location := 0
return location{location is the subscript i of the term ai equal to x, or 0 if x is not found}
*/
#include <iostream>
using namespace std;
int binarySearch(int a[],int size,int x)
{
//warning:'sizeof' on array function parameter 'a' will return size of 'int*'
//So, that array_size has passed as parameter
	/* i=leftend, j=rightend, mid=midpoint
		(point of search interval)
		loc=location
	*/
	int i,j,mid,loc;
	i=0; //startpoint=0 because of array index
	j=size-1; //last index of array

	while(i<j)	//exit only when one value is find out
	{	//i.e. exit when array index is only one
		mid=(i+j)/2; //split array into two sublist
		if(a[mid]<x) //leftend changes in search interval
			i=mid+1;
		else		 //rightend changes in search interval
			j=mid;
	}
	if(a[i]==x) //check a[i] that one value which exit from loop
		loc=i; 
	else	//if not found, location=-1;
		loc=-1;
	return loc;
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
	int loc=binarySearch(a,size,item); //arguments are array,array_size,search_value
	if(loc!=-1)
		cout<<endl<<"Search found. Location="<<loc+1;
	else
		cout<<endl<<"Search not found.";
	cout<<endl;
	system("pause");
	return 0;
}