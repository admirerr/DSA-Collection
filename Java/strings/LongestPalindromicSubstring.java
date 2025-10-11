// Problem: Longest Palindromic Substring
// Language: Java
// Description: Finds the longest palindromic substring in a given string. 
// Handles all edge cases (empty string, single character, multiple solutions).

import java.util.*;

public class LongestPalindromicSubstring {

    // Method to find the longest palindromic substring
    public static String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";

        int start = 0, end = 0; // indices of the longest palindrome
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);       // odd length palindrome
            int len2 = expandAroundCenter(s, i, i + 1);   // even length palindrome
            int len = Math.max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substring(start, end + 1);
    }

    // Helper method to expand palindrome around center
    private static int expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1; // length of palindrome
    }

    // Main method to take input and display output
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a string: ");
        String input = sc.nextLine();

        String result = longestPalindrome(input);

        System.out.println("\nLongest Palindromic Substring: " + result);
        System.out.println("Length: " + result.length());

        sc.close();
    }
}
