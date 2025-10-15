// Hacktoberfest 2025 Contribution
// Description: Java Program to convert an Infix expression to Postfix using Stack (OOP based)

import java.util.Stack;

public class InfixToPostfixConverter {

    // Function to check if a character is an operand (A-Z or a-z or digit)
    private boolean isOperand(char c) {
        return Character.isLetterOrDigit(c);
    }

    // Function to return precedence of operators
    private int precedence(char ch) {
        switch (ch) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
        }
        return -1;
    }

    // Main conversion function
    public String infixToPostfix(String expression) {
        StringBuilder result = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);

            // If the scanned character is an operand, add it to the output
            if (isOperand(c)) {
                result.append(c);
            }
            // If the scanned character is '(', push it to stack
            else if (c == '(') {
                stack.push(c);
            }
            // If the scanned character is ')', pop until '(' is found
            else if (c == ')') {
                while (!stack.isEmpty() && stack.peek() != '(') {
                    result.append(stack.pop());
                }
                stack.pop(); // remove '('
            }
            // Operator encountered
            else {
                while (!stack.isEmpty() && precedence(c) <= precedence(stack.peek())) {
                    result.append(stack.pop());
                }
                stack.push(c);
            }
        }

        // Pop all remaining operators from the stack
        while (!stack.isEmpty()) {
            result.append(stack.pop());
        }

        return result.toString();
    }

    // Main function for testing
    public static void main(String[] args) {
        InfixToPostfixConverter converter = new InfixToPostfixConverter();

        // Sample expressions
        String infix1 = "A+B*C";
        String infix2 = "(A+B)*C";
        String infix3 = "A+(B*C-(D/E^F)*G)*H";

        System.out.println("Infix : " + infix1);
        System.out.println("Postfix: " + converter.infixToPostfix(infix1));

        System.out.println("\nInfix : " + infix2);
        System.out.println("Postfix: " + converter.infixToPostfix(infix2));

        System.out.println("\nInfix : " + infix3);
        System.out.println("Postfix: " + converter.infixToPostfix(infix3));
    }
}
