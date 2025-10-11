public class KadaneAlgorithm {

    // Function to find maximum subarray sum
    public static int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("Array is empty");
        }
        // Initialize maxSoFar and maxEndingHere with the first element
        int maxSoFar = nums[0];
        int maxEndingHere = nums[0];

        // Iterate through the array starting from index 1
        for (int i = 1; i < nums.length; i++) {
            // Update maxEndingHere: either start a new subarray at current element
            // or extend the existing subarray
            maxEndingHere = Math.max(nums[i], maxEndingHere + nums[i]);

            // Update maxSoFar if the current maxEndingHere is greater
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }

    // Main method to test the algorithm
    public static void main(String[] args) {
        int[] nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int maxSum = maxSubArray(nums);
        System.out.println("Maximum Subarray Sum is: " + maxSum);
    }
}
