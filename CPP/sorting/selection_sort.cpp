#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &arr, int n) // Function to perform selection sort
{
 for (int i = 0; i < n - 1; i++) // Loop through each element in the array
 {
  int minIndex = i; // Assume the current index is the minimum

  for (int j = i + 1; j < n; j++) // Loop to find the minimum element in the unsorted part
  {
   if (arr[j] < arr[minIndex]) // If a smaller element is found
   {
    minIndex = j; // Update the index of the minimum element
   }
  }

  if (minIndex != i) // If the minimum element is not at the current position
  {
   swap(arr[i], arr[minIndex]); // Swap the found minimum element with the first element of the unsorted part
  }
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

 selectionSort(arr, n); // Call the selection sort function

 printArray(arr, n); // Print the sorted array
}
