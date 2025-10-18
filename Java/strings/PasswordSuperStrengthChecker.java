//PasswordStrengthChecker

import java.util.Scanner;
import java.util.regex.*;

public class PasswordStrengthChecker {

    // Checkpassword strength and return score
    public static int checkStrength(String password) {
        int score = 0;

        // Length checkk
        if (password.length() >= 8) score++;

        // Uppercasee + lowercase
        if (password.matches(".*[A-Z].*") && password.matches(".*[a-z].*")) score++;

        // Numberrs
        if (password.matches(".*[0-9].*")) score++;

        // Special characterrs
        if (password.matches(".*[!@#$%^&*()_+\\-=\\[\\]{};:'\",.<>/?].*")) score++;

        // Extraa strong if >= 12 chars
        if (password.length() >= 12) score++;

        return score;
    }

    // Suggesimprovement
    public static void suggestImprovements(String password) {
        if (password.length() < 8) 
            System.out.println("- Use at least 8 characters");
        if (!password.matches(".*[A-Z].*")) 
            System.out.println("- Add at least one uppercase letter");
        if (!password.matches(".*[a-z].*")) 
            System.out.println("- Add at least one lowercase letter");
        if (!password.matches(".*[0-9].*")) 
            System.out.println("- Add at least one number");
        if (!password.matches(".*[!@#$%^&*()_+\\-=\\[\\]{};:'\",.<>/?].*")) 
            System.out.println("- Add at least one special character (!@#$%^&*)");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a password to check: ");
        String password = sc.nextLine();

        int strength = checkStrength(password);

        System.out.println("\nPassword Strength Score: " + strength + "/5");

        switch (strength) {
            case 0, 1 -> System.out.println("Strength: Very Weakness ❌");
            case 2 -> System.out.println("Strength: Weak ⚠️");
            case 3 -> System.out.println("Strength: Moderate ✅");
            case 4 -> System.out.println("Strength: Strong 💪");
            case 5 -> System.out.println("Strength: Super Strong 🔥");
        }

        if (strength < 5) {
            System.out.println("\nSuggestions to improve your password:");
            suggestImprovements(password);
        }
    }
}
