//quick sort
#include <iostream>
using namespace std;
int partition(int a[],int left,int right)
{
	//pivot makes partition in two group
	int pivot=a[right];
	int wall=left;
	//wall means making smaller on left,bigger on right
	for(int i=left; i<right; i++){
		if(a[i]<pivot){
			//exit when pivot is less in array
			//swap(a[i],a[wall]);
			int temp=a[wall];
			a[wall]=a[i];
			a[i]=temp;
			wall++;
			//wall stop at pivot index
		}
	}
	//swap(a[wall],a[right]);
	a[right]=a[wall];
	a[wall]=pivot; //pivot as temp a[right]
	return wall; //returns pivot index
}
void quickSort(int a[],int begin,int end)
{
	//quickSort() stops when only one element left
	if(begin<end){
		int pi=partition(a,begin,end); //pi (pivot index)
		//calls repeatedly
		quickSort(a,begin,pi-1); //partition 1 < pi
		quickSort(a,pi+1,end); //partition 2 > pi
	}
}
int main()
{
	int a[]={6,8,1};
	int n;
	n=sizeof(a)/sizeof(int);
	cout<<"Before sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	quickSort(a,0,n-1);
	cout<<"\nAfter sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	system("pause");
	return 0;
}