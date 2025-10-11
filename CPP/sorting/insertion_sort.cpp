#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{ // Function to perform insertion sort on the vector

 for (int i = 1; i < n; i++)
 { // Loop through each element starting from the second element
  int key = arr[i];
  int j = i - 1;
  while (j >= 0 && arr[j] > key)
  { // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
   arr[j + 1] = arr[j];
   j--;
  }
  arr[j + 1] = key;
 }
}

void printArray(vector<int> &arr, int n) // Function to print the elements of the vector
{
 cout << "Sorted Array ";
 for (int i = 0; i < n; i++)
 {
  cout << arr[i] << " ";
 }
}

void inputArr(vector<int> &arr) // Function to input elements into the vector
{

 int n;
 cout << "Enter number of elements ";
 cin >> n;
 cout << "Enter elements ";

 for (int i = 0; i < n; i++) // Loop to read n elements
 {
  int x;
  cin >> x;
  arr.push_back(x);
 }
}

int main()
{
 vector<int> arr; // Declare a vector to hold the array elements

 inputArr(arr); // Input elements into the vector

 int n = arr.size(); // Get the size of the vector

 insertionSort(arr, n); // Call the insertion sort function

 printArray(arr, n); // Print the sorted array
}
