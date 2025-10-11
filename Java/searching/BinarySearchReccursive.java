public class BinarySearchReccursive {
    public static void main(String[] args) {
        int[] arr = { 2, 3, 4, 10, 40 };
        int target = 10;
        int result = binarySearch(arr, target, 0, arr.length - 1);
        if (result == -1) {
            System.out.println("Element not found in the array");
        } else {
            System.out.println("Element found at index: " + result);
        }
    }

    static int binarySearch(int[] arr, int target, int left, int right) {
        if (right >= left) {
            int mid = left + (right - left) / 2;

            // Check if the target is present at mid
            if (arr[mid] == target) {
                return mid;
            }

            // If target is smaller than mid, it can only be present in left subarray
            if (arr[mid] > target) {
                return binarySearch(arr, target, left, mid - 1);
            }

            // Else the target can only be present in right subarray
            return binarySearch(arr, target, mid + 1, right);
        }

        // Target is not present in the array
        return -1;
    }
}
