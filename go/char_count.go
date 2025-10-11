package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
    fmt.Print("Enter the string: ")

    // Create a reader for the input
    reader := bufio.NewReader(os.Stdin)

    // Read a string until the newline character
    input, err := reader.ReadString('\n')
    if err != nil {
        fmt.Println("Error reading input string:", err)
        return
    }

    // Remove the trailing newline or carriage return from the input string.
    input = strings.TrimSpace(input)

    // Create a map to store character count.
    charCounts := make(map[rune]int)

    // Loop over the string to count the characters.
    for _, char := range input {
        charCounts[char]++
    }

    fmt.Println("\nCharacter counts:")
    for char, count := range charCounts {
        fmt.Printf("'%c': %d\n", char, count)
    }
}
