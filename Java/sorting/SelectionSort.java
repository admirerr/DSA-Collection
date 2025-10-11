/*
 * Selection Sort is a simple comparison-based sorting algorithm.
 * The idea is to repeatedly find the minimum element from the unsorted part
 * and place it at the beginning of the array.
 */

public class SelectionSort {
    public static void main(String[] args) {
        // Initialize an array of integers
        int[] array = { 4, 1, 9, 7, 2, 6, 5, 3, 8 };

        // Print the array before sorting
        System.out.print("Before Sorting: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }

        // Outer loop - iterate over each element of the array
        for (int i = 0; i < array.length - 1; i++) {
            int minIndex = i; // Assume the current element is the minimum

            // Inner loop - find the minimum element in the unsorted part
            for (int j = i + 1; j < array.length; j++) {
                if (array[j] < array[minIndex]) {
                    minIndex = j; // Update minIndex if a smaller element is found
                }
            }

            // Swap the found minimum element with the first element of the unsorted part
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }

        // Print the array after sorting
        System.out.print("\nAfter Sorting: ");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
    }
}
