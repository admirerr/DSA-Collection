public class LinearSearch {

    /**
     * Searches for a target value in an array using the linear search algorithm.
     * @param arr The array to be searched.
     * @param target The value to search for.
     * @return The index of the target if found; otherwise, -1.
     */
    public static int search(int[] arr, int target) {
        int n = arr.length;
        // Step through the array sequentially
        for (int i = 0; i < n; i++) {
            // If the current element matches the target, return its index
            if (arr[i] == target) {
                return i;
            }
        }
        // If the loop completes, the element was not found
        return -1;
    }

    public static void main(String[] args) {
        int[] numbers = {22, 35, 12, 4, 10, 40, 19};
        int target = 10;

        int result = search(numbers, target);

        if (result == -1) {
            System.out.println("Element is not present in the array.");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }
}
