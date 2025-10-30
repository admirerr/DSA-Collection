import java.util.Arrays;

public class LeftRotation {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        int rotations = 2; // Number of positions to rotate left

        System.out.println("Original array: " + Arrays.toString(arr));

        leftRotate(arr, rotations);

        System.out.println("Array after left rotation: " + Arrays.toString(arr));
    }

    public static void leftRotate(int[] arr, int rotations) {
        int n = arr.length;
        
        rotations = rotations % n;

        int[] temp = new int[rotations];
        for (int i = 0; i < rotations; i++) {
            temp[i] = arr[i];
        }

        for (int i = rotations; i < n; i++) {
            arr[i - rotations] = arr[i];
        }

        for (int i = 0; i < rotations; i++) {
            arr[n - rotations + i] = temp[i];
        }
    }
}