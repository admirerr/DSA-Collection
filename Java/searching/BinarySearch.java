import java.util.*;

public class BinarySearch {
    public static void main(String[] args) {
        // Sample sorted array for demonstration
        int a[] = {1, 5, 8, 9, 12, 13, 17, 19};
        int size = a.length;

        System.out.println("Array list:");
        for (int i : a) {
            System.out.println(i);
        }
        System.out.println();

        // Input: value to search for
        System.out.print("Enter Search item: ");
        Scanner sc = new Scanner(System.in);
        int item = sc.nextInt();
        System.out.print('\n');

        // Call the binary search function and store result
        int loc = search(a, size, item);

        // Output: location if found, else not found
        if (loc != -1)
            System.out.println("Search found. Location=" + (loc + 1));
        else
            System.out.println("Search not found.");
    }

    // Iterative binary search function: returns index of found item, -1 if not found
    public static int search(int a[], int size, int x) {
        int i, j, mid, loc;
        i = 0;
        j = size - 1;

        // Loop continues while there is more than one element in interval
        while (i < j) {
            mid = (i + j) / 2;

            // If x is greater, search right half
            if (a[mid] < x)
                i = mid + 1;
            else // Otherwise, search left half
                j = mid;
        }

        // Final position check: if found, return index
        if (a[i] == x)
            loc = i;
        else
            loc = -1;
        return loc;
    }
}
