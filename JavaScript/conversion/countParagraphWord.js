function countParagraphWord(paragraph) {
    if (!paragraph || typeof paragraph !== "string") return 0;

    // Trim spaces and split by whitespace
    const words = paragraph.trim().split(/\s+/);

    // Count only non-empty words
    return words.filter(word => word.length > 0).length;
}

// Example usage:
const paragraph = "Hello world! This is a sample paragraph.";
console.log(countParagraphWord(paragraph)); // Output: 7
