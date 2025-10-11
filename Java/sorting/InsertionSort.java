/*
 * Insertion Sort is a simple comparison-based sorting algorithm.
 * It builds the sorted array one element at a time by inserting each
 * element into its correct position relative to the sorted portion.
 */

public class InsertionSort {
    public static void main(String[] args) {
        // Initialize an array of integers
        int[] array = { 4, 1, 9, 7, 2, 6, 5, 3, 8 };

        // Print the array before sorting
        System.out.print("Before Sorting: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }

        // Start from the second element (index 1)
        for (int i = 1; i < array.length; i++) {
            int key = array[i]; // Element to be inserted
            int j = i - 1;

            // Shift elements of the sorted part that are greater than key
            // one position to the right
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j--;
            }

            // Insert the key into its correct position
            array[j + 1] = key;
        }

        // Print the array after sorting
        System.out.print("\nAfter Sorting: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }
}
