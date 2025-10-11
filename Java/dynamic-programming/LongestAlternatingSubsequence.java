import java.util.Arrays;

public final class LongestAlternatingSubsequence {
    private LongestAlternatingSubsequence() {
    }

    static int alternatingLength(int[] arr, int n) {
        if (n == 0) {
            return 0;
        }

        int[][] las = new int[n][2];

        for (int i = 0; i < n; i++) {
            las[i][0] = 1;
            las[i][1] = 1;
        }

        int result = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i] && las[i][0] < las[j][1] + 1) {
                    las[i][0] = las[j][1] + 1;
                }

                if (arr[j] > arr[i] && las[i][1] < las[j][0] + 1) {
                    las[i][1] = las[j][0] + 1;
                }
            }
            result = Math.max(result, Math.max(las[i][0], las[i][1]));
        }
        return result;
    }

    public static void main(String[] args) {
        int[] arr1 = {10, 22, 9, 33, 49, 50, 31, 60};
        int length1 = alternatingLength(arr1, arr1.length);
        System.out.println("Array: " + Arrays.toString(arr1));
        System.out.println("Length of the longest alternating subsequence is: " + length1);

        System.out.println("\n----------------------------------------\n");

        int[] arr2 = {1, 5, 4, 8, 2, 7, 3};
        int length2 = alternatingLength(arr2, arr2.length);
        System.out.println("Array: " + Arrays.toString(arr2));
        System.out.println("Length of the longest alternating subsequence is: " + length2);
    }
}