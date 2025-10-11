//merge sort
#include <iostream>
using namespace std;
void merge(int a[],int left,int mid,int right)
{
	//making two list(i.e. array)
	//specifying sizes of array(index start from 0)
	int arrSize1=mid-left+1; //+1 is added to make real size
	int arrSize2=right-mid; //right-(mid+1)+1;
	//creating temporary array
	int *list1=new int[arrSize1];
	int *list2=new int[arrSize2];
	for(int i=0;i<arrSize1;i++)
		list1[i]=a[left+i];
	for(int i=0;i<arrSize2;i++)
		list2[i]=a[(mid+1)+i];
	int index1=0;
	int index2=0;
	int indexMerged=left; //as left=0;
	//checking index of list
	while(index1<arrSize1 && index2<arrSize2){
		//comparing min value from 2 lists
		if(list1[index1]<list2[index2]){
			a[indexMerged++]=list1[index1++];
			//index1++;
		}
		else{
			a[indexMerged++]=list2[index2++];
			//index2++;
		}
		//indexMerged++;
	}
	//copying remaining elements if any
	while(index1<arrSize1){
		a[indexMerged++]=list1[index1++];
		//index1++;
		//indexMerged++;
	}
	//copying remaining elements if any
	while(index2<arrSize2){
		a[indexMerged++]=list2[index2++];
		//index2++;
		//indexMerged++;
	}
	delete []list1;
	delete []list2;
}
void mergeSort(int a[],int begin,int end)
{
	if(begin<end){
		int mid=(begin+end)/2;
		//calls recursively and merged
		mergeSort(a,begin,mid);
		mergeSort(a,mid+1,end);
		//merge recursively and sorted
		merge(a,begin,mid,end);
	}
}

int main()
{
	int a[]={9,4,7,8,3,5,1,2};
	int n;
	n=sizeof(a)/sizeof(int);
	cout<<"Before sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	mergeSort(a,0,n-1);
	cout<<"\nAfter sorting array:\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
	system("pause");
	return 0;
}