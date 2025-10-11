/*
 * Merge Sort is a divide-and-conquer algorithm that works by:
 * 1. Dividing the array into two halves
 * 2. Recursively sorting both halves
 * 3. Merging the sorted halves back together
 * 
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

import java.util.*;

public class MergeSort {
    public static void main(String args[]) {
        // Initialize an array of integers
        int[] arr = { 9, 4, 7, 6, 3, 1, 5 };
        
        // Print the array before sorting
        System.out.print("Before Sorting: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        
        // Call merge sort algorithm
        Solution.mergeSort(arr, 0, arr.length - 1);
        
        // Print the array after sorting
        System.out.print("After Sorting: ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
class Solution {
    // Merge two sorted halves of the array
    private static void merge(int[] arr, int low, int mid, int high) {
        ArrayList<Integer> temp = new ArrayList<>();
        int left = low;      // Starting index of left half
        int right = mid + 1; // Starting index of right half

        // Store elements in sorted order
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.add(arr[left]);
                left++;
            } else {
                temp.add(arr[right]);
                right++;
            }
        }

        // Add remaining elements from left half
        while (left <= mid) {
            temp.add(arr[left]);
            left++;
        }

        // Add remaining elements from right half
        while (right <= high) {
            temp.add(arr[right]);
            right++;
        }

        // Copy merged elements back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp.get(i - low);
        }
    }

    // Recursive merge sort function
    public static void mergeSort(int[] arr, int low, int high) {
        if (low >= high) return; // Base case
        
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);        // Sort left half
        mergeSort(arr, mid + 1, high);   // Sort right half
        merge(arr, low, mid, high);      // Merge sorted halves
    }
}