/**
 * Problem: Counting Sort Algorithm
 * 
 * Description:
 * Counting Sort is a non-comparison based sorting algorithm that sorts elements
 * by counting the number of occurrences of each unique element in the array.
 * It works by determining, for each input element, the number of elements that
 * are less than it. This information is used to place the element directly into
 * its correct position in the sorted array.
 * 
 * Algorithm:
 * 1. Find the range of input data (max and min values)
 * 2. Create a count array to store frequency of each element
 * 3. Modify count array by adding previous counts (cumulative count)
 * 4. Build output array by placing elements at their correct positions
 * 5. Copy output array back to original array
 * 
 * Time Complexity: O(n + k) where n = number of elements, k = range of input
 * Space Complexity: O(n + k)
 * 
 * Best for:
 * - Small range of integers
 * - When range of input is not significantly greater than number of elements
 * - Stable sorting is required
 * 
 * Advantages:
 * - Linear time complexity for small range of integers
 * - Stable sorting algorithm (maintains relative order)
 * - Simple to understand and implement
 * 
 * Disadvantages:
 * - Not suitable for large range of values
 * - Only works with non-negative integers (can be modified for negatives)
 * - Requires extra space proportional to the range of data
 * 
 * @author DSA-Collection Contributors
 * @date October 2025
 */

import java.util.Arrays;

public class CountingSort {

    /**
     * Sorts an array of non-negative integers using Counting Sort algorithm.
     * 
     * @param arr The array to be sorted (must contain non-negative integers)
     * @throws IllegalArgumentException if array contains negative numbers
     */
    public static void countingSort(int[] arr) {
        // Handle edge cases
        if (arr == null || arr.length <= 1) {
            return;
        }

        // Step 1: Find the range of input data (max and min)
        int max = arr[0];
        int min = arr[0];
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        // Check for negative numbers
        if (min < 0) {
            throw new IllegalArgumentException(
                "Counting Sort requires non-negative integers. Found: " + min
            );
        }

        // Step 2: Create count array to store frequency of each element
        // Size is (max + 1) to accommodate all values from 0 to max
        int range = max + 1;
        int[] count = new int[range];

        // Count occurrences of each element
        for (int i = 0; i < arr.length; i++) {
            count[arr[i]]++;
        }

        // Step 3: Modify count array by doing cumulative count
        // count[i] now contains actual position of this element in output array
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        // Step 4: Build the output array
        // We build from right to left to maintain stability
        int[] output = new int[arr.length];
        for (int i = arr.length - 1; i >= 0; i--) {
            int element = arr[i];
            int position = count[element] - 1;
            output[position] = element;
            count[element]--; // Decrease count for next occurrence
        }

        // Step 5: Copy the sorted elements back to original array
        System.arraycopy(output, 0, arr, 0, arr.length);
    }

    /**
     * Alternative implementation that handles negative numbers as well.
     * Uses offset to handle negative values.
     * 
     * @param arr The array to be sorted (can contain negative integers)
     */
    public static void countingSortWithNegatives(int[] arr) {
        if (arr == null || arr.length <= 1) {
            return;
        }

        // Find max and min to determine range and offset
        int max = arr[0];
        int min = arr[0];
        
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            if (arr[i] < min) {
                min = arr[i];
            }
        }

        int range = max - min + 1;
        int offset = -min; // Offset to handle negative numbers
        
        // Create count array
        int[] count = new int[range];

        // Count occurrences (with offset for negative numbers)
        for (int i = 0; i < arr.length; i++) {
            count[arr[i] + offset]++;
        }

        // Modify count array (cumulative)
        for (int i = 1; i < range; i++) {
            count[i] += count[i - 1];
        }

        // Build output array (maintain stability)
        int[] output = new int[arr.length];
        for (int i = arr.length - 1; i >= 0; i--) {
            int element = arr[i];
            int position = count[element + offset] - 1;
            output[position] = element;
            count[element + offset]--;
        }

        // Copy back to original array
        System.arraycopy(output, 0, arr, 0, arr.length);
    }

    /**
     * Utility method to print array
     */
    private static void printArray(String label, int[] arr) {
        System.out.print(label + ": ");
        System.out.println(Arrays.toString(arr));
    }

    /**
     * Verify if array is sorted
     */
    private static boolean isSorted(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    /**
     * Main method with comprehensive test cases
     */
    public static void main(String[] args) {
        System.out.println("=== Counting Sort Algorithm Implementation ===\n");

        // Test Case 1: Standard array
        System.out.println("Test Case 1: Standard Array");
        int[] test1 = {4, 2, 2, 8, 3, 3, 1};
        printArray("Original", test1);
        countingSort(test1);
        printArray("Sorted  ", test1);
        System.out.println("Is sorted: " + isSorted(test1));
        System.out.println();

        // Test Case 2: Already sorted array
        System.out.println("Test Case 2: Already Sorted Array");
        int[] test2 = {1, 2, 3, 4, 5};
        printArray("Original", test2);
        countingSort(test2);
        printArray("Sorted  ", test2);
        System.out.println("Is sorted: " + isSorted(test2));
        System.out.println();

        // Test Case 3: Reverse sorted array
        System.out.println("Test Case 3: Reverse Sorted Array");
        int[] test3 = {9, 7, 5, 3, 1};
        printArray("Original", test3);
        countingSort(test3);
        printArray("Sorted  ", test3);
        System.out.println("Is sorted: " + isSorted(test3));
        System.out.println();

        // Test Case 4: Array with duplicates
        System.out.println("Test Case 4: Array with Many Duplicates");
        int[] test4 = {5, 2, 8, 2, 9, 1, 5, 5};
        printArray("Original", test4);
        countingSort(test4);
        printArray("Sorted  ", test4);
        System.out.println("Is sorted: " + isSorted(test4));
        System.out.println();

        // Test Case 5: Single element
        System.out.println("Test Case 5: Single Element");
        int[] test5 = {42};
        printArray("Original", test5);
        countingSort(test5);
        printArray("Sorted  ", test5);
        System.out.println("Is sorted: " + isSorted(test5));
        System.out.println();

        // Test Case 6: All same elements
        System.out.println("Test Case 6: All Same Elements");
        int[] test6 = {7, 7, 7, 7, 7};
        printArray("Original", test6);
        countingSort(test6);
        printArray("Sorted  ", test6);
        System.out.println("Is sorted: " + isSorted(test6));
        System.out.println();

        // Test Case 7: Large numbers
        System.out.println("Test Case 7: Large Numbers");
        int[] test7 = {100, 50, 200, 75, 125};
        printArray("Original", test7);
        countingSort(test7);
        printArray("Sorted  ", test7);
        System.out.println("Is sorted: " + isSorted(test7));
        System.out.println();

        // Test Case 8: With zeros
        System.out.println("Test Case 8: Array with Zeros");
        int[] test8 = {0, 5, 0, 3, 0, 2};
        printArray("Original", test8);
        countingSort(test8);
        printArray("Sorted  ", test8);
        System.out.println("Is sorted: " + isSorted(test8));
        System.out.println();

        // Test Case 9: Negative numbers (using alternative method)
        System.out.println("Test Case 9: Array with Negative Numbers (Alternative Method)");
        int[] test9 = {-5, 2, -3, 8, 0, -1, 4};
        printArray("Original", test9);
        countingSortWithNegatives(test9);
        printArray("Sorted  ", test9);
        System.out.println("Is sorted: " + isSorted(test9));
        System.out.println();

        // Test Case 10: Error handling
        System.out.println("Test Case 10: Error Handling (Negative Numbers)");
        try {
            int[] test10 = {5, -3, 8, 2};
            printArray("Attempting to sort", test10);
            countingSort(test10); // Should throw exception
            System.out.println("ERROR: Should have thrown exception!");
        } catch (IllegalArgumentException e) {
            System.out.println("Correctly caught exception: " + e.getMessage());
        }
        System.out.println();

        System.out.println("=== All tests completed successfully! ===");
    }
}
