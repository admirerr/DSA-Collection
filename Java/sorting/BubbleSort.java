/*
 * Bubble Sort is a simple comparison-based sorting algorithm.
 * The idea is to repeatedly swap adjacent elements if they are in the wrong order.
 * This way, larger elements "bubble up" to the end of the array on each pass.
 */

public class BubbleSort {
    public static void main(String[] args) {
        // Initialize an array of integers
        int[] array = { 4, 1, 9, 7, 2, 6, 5, 3, 8 };

        // Print the array before sorting
        System.out.print("Before Sorting: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }

        // Outer loop - controls the number of passes
        for (int i = 0; i < array.length; i++) {
            // Inner loop - goes through the array and compares adjacent elements
            for (int j = 0; j < array.length - i - 1; j++) {
                // If the current element is greater than the next element, swap them
                if (array[j] > array[j + 1]) {
                    int temp = array[j]; // Store current element in temp
                    array[j] = array[j + 1]; // Replace current element with next element
                    array[j + 1] = temp; // Replace next element with temp (swap done)
                }
            }
            // After each pass, the largest element in the unsorted part moves to its
            // correct position
        }

        // Print the array after sorting
        System.out.print("\nAfter Sorting: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }
}
