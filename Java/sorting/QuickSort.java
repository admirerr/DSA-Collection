public class QuickSort {
    
    // Main method to test the quick sort algorithm
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        
        System.out.println("Original array:");
        printArray(arr);
        
        // Call quickSort on the entire array
        quickSort(arr, 0, arr.length - 1);
        
        System.out.println("\nSorted array:");
        printArray(arr);
    }
    
    // Quick sort method - sorts array between low and high indices
    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // Find partition index - element is now in correct position
            int partitionIndex = partition(arr, low, high);
            
            // Recursively sort elements before and after partition
            quickSort(arr, low, partitionIndex - 1);  // Sort left half
            quickSort(arr, partitionIndex + 1, high); // Sort right half
        }
    }
    
    // Partition method - places pivot in correct position
    public static int partition(int[] arr, int low, int high) {
        // Choose rightmost element as pivot
        int pivot = arr[high];
        
        // Index of smaller element (indicates right position of pivot)
        int i = (low - 1);
        
        // Traverse through array and rearrange elements
        for (int j = low; j < high; j++) {
            // If current element is smaller than or equal to pivot
            if (arr[j] <= pivot) {
                i++; // Increment index of smaller element
                swap(arr, i, j); // Swap elements
            }
        }
        
        // Place pivot in correct position
        swap(arr, i + 1, high);
        return i + 1; // Return partition index
    }
    
    // Helper method to swap two elements in array
    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Helper method to print array
    public static void printArray(int[] arr) {
        for (int value : arr) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
}