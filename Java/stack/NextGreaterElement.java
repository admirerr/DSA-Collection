// Problem: Next Greater Element
// Language: Java
// Description: For each element in an array, find the next greater element to its right.
// Uses stack to solve efficiently in O(n) time.

import java.util.*;

public class NextGreaterElement {

    // Method to find next greater elements
    public static int[] nextGreaterElement(int[] arr) {
        int n = arr.length;
        int[] result = new int[n];          // Array to store next greater elements
        Stack<Integer> stack = new Stack<>(); // Stack to keep track of elements

        for (int i = n - 1; i >= 0; i--) {
            // Pop elements smaller than current element
            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }

            // If stack is empty, no greater element to the right
            result[i] = stack.isEmpty() ? -1 : stack.peek();

            // Push current element to stack
            stack.push(arr[i]);
        }

        return result;
    }

    // Main method to take input and print output
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter " + n + " elements:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int[] nge = nextGreaterElement(arr);

        System.out.println("\nNext Greater Elements:");
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i] + " -> " + nge[i]);
        }

        sc.close();
    }
}
