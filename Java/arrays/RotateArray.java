// File: RotateArray.java
// Folder: Java/arrays/RotateArray.java
// Author: Harsh Dubey
// Description: This program rotates an array to the left or right based on user input.

import java.util.Scanner;
import java.util.Arrays; // <-- Add this import

public class RotateArray {

    // Function to rotate array to the right by k positions
    public static void rotateRight(int[] arr, int k) {
        int n = arr.length;
        k = k % n; // handle rotations greater than array size
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
    }

    // Function to rotate array to the left by k positions
    public static void rotateLeft(int[] arr, int k) {
        int n = arr.length;
        k = k % n; // handle rotations greater than array size
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
        reverse(arr, 0, n - 1);
    }

    // Helper function to reverse elements in array from index start to end
    public static void reverse(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the size of the array:");
        int n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.println("Original Array: " + Arrays.toString(arr));

        System.out.println("Enter number of positions to rotate:");
        int k = sc.nextInt();

        System.out.println("Enter direction (L for left, R for right):");
        char direction = sc.next().toUpperCase().charAt(0);

        if (direction == 'L') {
            rotateLeft(arr, k);
            System.out.println("Array after left rotation by " + k + " positions: " + Arrays.toString(arr));
        } else if (direction == 'R') {
            rotateRight(arr, k);
            System.out.println("Array after right rotation by " + k + " positions: " + Arrays.toString(arr));
        } else {
            System.out.println("Invalid direction entered!");
        }

        sc.close();
    }
}
