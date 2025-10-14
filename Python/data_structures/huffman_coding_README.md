# Huffman Coding Implementation

## Overview
Huffman Coding adalah algoritma kompresi lossless yang menggunakan frekuensi karakter untuk membuat kode biner yang optimal. Karakter yang sering muncul mendapat kode pendek, sedangkan karakter jarang mendapat kode panjang.

## Features
- ✅ Complete implementation in Python, C++, and JavaScript
- ✅ Handles edge cases (single character, repeated characters)
- ✅ Interactive mode for testing
- ✅ Tree visualization
- ✅ Compression ratio calculation
- ✅ Comprehensive test cases

## Algorithm Complexity
- **Time Complexity**: O(n log n) untuk membangun tree
- **Space Complexity**: O(n) untuk menyimpan frequency table dan codes

## How It Works

### 1. Frequency Analysis
```
Input: "hello world"
Frequency table:
  'h': 1
  'e': 1  
  'l': 3
  'o': 2
  ' ': 1
  'w': 1
  'r': 1
  'd': 1
```

### 2. Tree Construction
- Buat leaf nodes untuk setiap karakter dengan frekuensinya
- Gabungkan 2 nodes dengan frekuensi terendah menjadi internal node
- Ulangi sampai hanya ada 1 root node

### 3. Code Generation
- Traverse tree dari root ke leaf
- Left child = "0", Right child = "1"
- Kode untuk setiap karakter = path dari root ke leaf

### 4. Encoding/Decoding
- **Encode**: Ganti setiap karakter dengan kode Huffman-nya
- **Decode**: Gunakan reverse mapping untuk mengembalikan karakter

## Example Usage

### Python
```python
from huffman_coding import HuffmanCoding

huffman = HuffmanCoding()
text = "hello world"

# Encode
encoded_text, freq_table = huffman.encode(text)
print(f"Encoded: {encoded_text}")

# Decode
decoded_text = huffman.decode(encoded_text, freq_table)
print(f"Decoded: {decoded_text}")

# Compression ratio
ratio = huffman.get_compression_ratio(text, encoded_text)
print(f"Compression: {ratio:.2f}%")
```

### C++
```cpp
#include "huffman_coding.cpp"

HuffmanCoding huffman;
string text = "hello world";

// Encode
auto result = huffman.encode(text);
string encodedText = result.first;
unordered_map<char, int> freqTable = result.second;

// Decode
string decodedText = huffman.decode(encodedText, freqTable);
```

### JavaScript
```javascript
const { HuffmanCoding } = require('./huffman_coding.js');

const huffman = new HuffmanCoding();
const text = "hello world";

// Encode
const { encodedText, freqTable } = huffman.encode(text);
console.log(`Encoded: ${encodedText}`);

// Decode
const decodedText = huffman.decode(encodedText, freqTable);
console.log(`Decoded: ${decodedText}`);
```

## Test Cases

The implementation includes comprehensive test cases:

1. **Normal text**: "hello world"
2. **Repeated characters**: "aabbbcccc"  
3. **Complex text**: "mississippi"
4. **Long text**: "The quick brown fox jumps over the lazy dog"
5. **Edge case - single char**: "aaaaaaaaaa"
6. **Edge case - unique chars**: "abc"

## Edge Cases Handled

- **Empty string**: Returns empty encoded text
- **Single character**: Uses "0" as code
- **All same characters**: Efficient encoding with single code
- **All unique characters**: Balanced tree structure

## Compression Performance

Typical compression ratios:
- **Repeated text**: 60-80% compression
- **Normal text**: 20-40% compression  
- **Random text**: 0-10% compression

## File Structure

```
data_structures/
├── huffman_coding.py      # Python implementation
├── huffman_coding.cpp     # C++ implementation  
└── huffman_coding.js      # JavaScript implementation
```

## Running the Code

### Python
```bash
python huffman_coding.py
```

### C++
```bash
g++ -o huffman huffman_coding.cpp
./huffman
```

### JavaScript
```bash
node huffman_coding.js
```

## Interactive Mode

All implementations include interactive mode for testing:
- Encode custom text
- Decode previously encoded text
- Run comprehensive demo
- View compression statistics

## Applications

Huffman Coding is used in:
- **File compression** (ZIP, GZIP)
- **Image compression** (JPEG)
- **Network protocols**
- **Database systems**
- **Text processing systems**

## Future Enhancements

Potential improvements:
- Adaptive Huffman coding
- Canonical Huffman codes
- Parallel encoding/decoding
- Memory-optimized tree structures
- Integration with other compression algorithms
