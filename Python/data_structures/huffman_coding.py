"""
Huffman Coding Implementation
============================

Huffman coding adalah algoritma kompresi lossless yang menggunakan frekuensi karakter
untuk membuat kode biner yang optimal. Karakter yang sering muncul mendapat kode pendek,
sedangkan karakter jarang mendapat kode panjang.

Kompleksitas:
- Time: O(n log n) untuk membangun tree
- Space: O(n) untuk menyimpan frequency table dan codes

Author: [Your Name]
Date: 2024
"""

import heapq
from collections import defaultdict
import json


class HuffmanNode:
    """Node untuk Huffman Tree"""
    def __init__(self, char=None, freq=0, left=None, right=None):
        self.char = char  # karakter (None untuk internal nodes)
        self.freq = freq  # frekuensi
        self.left = left  # child kiri
        self.right = right  # child kanan
    
    def __lt__(self, other):
        """Untuk priority queue - bandingkan berdasarkan frekuensi"""
        return self.freq < other.freq


class HuffmanCoding:
    """Implementasi lengkap Huffman Coding"""
    
    def __init__(self):
        self.codes = {}  # mapping karakter ke kode biner
        self.reverse_codes = {}  # mapping kode biner ke karakter
        self.root = None  # root dari huffman tree
    
    def _build_frequency_table(self, text):
        """Membangun tabel frekuensi karakter"""
        freq_table = defaultdict(int)
        for char in text:
            freq_table[char] += 1
        return freq_table
    
    def _build_huffman_tree(self, freq_table):
        """Membangun Huffman Tree menggunakan priority queue"""
        # Buat heap dengan semua karakter sebagai leaf nodes
        heap = []
        for char, freq in freq_table.items():
            node = HuffmanNode(char, freq)
            heapq.heappush(heap, node)
        
        # Bangun tree dengan menggabungkan nodes dengan frekuensi terendah
        while len(heap) > 1:
            # Ambil 2 nodes dengan frekuensi terendah
            left = heapq.heappop(heap)
            right = heapq.heappop(heap)
            
            # Buat internal node baru
            merged = HuffmanNode(freq=left.freq + right.freq, left=left, right=right)
            heapq.heappush(heap, merged)
        
        return heapq.heappop(heap)  # root node
    
    def _generate_codes(self, node, current_code=""):
        """Generate kode biner untuk setiap karakter (DFS traversal)"""
        if node is None:
            return
        
        # Jika ini leaf node (memiliki karakter)
        if node.char is not None:
            if current_code == "":  # Edge case: hanya 1 karakter
                current_code = "0"
            self.codes[node.char] = current_code
            self.reverse_codes[current_code] = node.char
            return
        
        # Traverse ke kiri (tambah "0")
        self._generate_codes(node.left, current_code + "0")
        # Traverse ke kanan (tambah "1")
        self._generate_codes(node.right, current_code + "1")
    
    def encode(self, text):
        """Encode text menggunakan Huffman coding"""
        if not text:
            return "", {}
        
        # Reset previous state
        self.codes = {}
        self.reverse_codes = {}
        
        # Build frequency table
        freq_table = self._build_frequency_table(text)
        
        # Handle edge case: hanya 1 karakter unik
        if len(freq_table) == 1:
            char = list(freq_table.keys())[0]
            self.codes[char] = "0"
            self.reverse_codes["0"] = char
            encoded_text = "0" * freq_table[char]
            return encoded_text, dict(freq_table)
        
        # Build Huffman tree
        self.root = self._build_huffman_tree(freq_table)
        
        # Generate codes
        self._generate_codes(self.root)
        
        # Encode text
        encoded_text = ""
        for char in text:
            encoded_text += self.codes[char]
        
        return encoded_text, dict(freq_table)
    
    def decode(self, encoded_text, freq_table):
        """Decode text dari Huffman coding"""
        if not encoded_text:
            return ""
        
        # Rebuild Huffman tree dari frequency table
        self.codes = {}
        self.reverse_codes = {}
        
        # Handle edge case: hanya 1 karakter unik
        if len(freq_table) == 1:
            char = list(freq_table.keys())[0]
            self.codes[char] = "0"
            self.reverse_codes["0"] = char
            return char * freq_table[char]
        
        # Rebuild tree
        self.root = self._build_huffman_tree(freq_table)
        self._generate_codes(self.root)
        
        # Decode text
        decoded_text = ""
        current_code = ""
        
        for bit in encoded_text:
            current_code += bit
            if current_code in self.reverse_codes:
                decoded_text += self.reverse_codes[current_code]
                current_code = ""  # Reset untuk karakter berikutnya
        
        return decoded_text
    
    def get_compression_ratio(self, original_text, encoded_text):
        """Hitung compression ratio"""
        original_bits = len(original_text) * 8  # ASCII = 8 bits per char
        encoded_bits = len(encoded_text)
        return (1 - encoded_bits / original_bits) * 100
    
    def print_codes(self):
        """Print semua kode Huffman"""
        print("\nHuffman Codes:")
        print("-" * 30)
        for char, code in sorted(self.codes.items()):
            if char == '\n':
                print(f"'\\n': {code}")
            elif char == ' ':
                print(f"' ': {code}")
            else:
                print(f"'{char}': {code}")
    
    def visualize_tree(self, node=None, prefix="", is_last=True):
        """Visualisasi Huffman tree (recursive)"""
        if node is None:
            node = self.root
        
        if node is None:
            return
        
        # Print current node
        connector = "└── " if is_last else "├── "
        if node.char is not None:
            char_display = f"'{node.char}'" if node.char != ' ' else "' '"
            print(f"{prefix}{connector}{char_display} (freq: {node.freq})")
        else:
            print(f"{prefix}{connector}Internal (freq: {node.freq})")
        
        # Print children
        if node.left is not None or node.right is not None:
            new_prefix = prefix + ("    " if is_last else "│   ")
            
            if node.right is not None:
                self.visualize_tree(node.right, new_prefix, node.left is None)
            if node.left is not None:
                self.visualize_tree(node.left, new_prefix, True)


def demo_huffman_coding():
    """Demo penggunaan Huffman Coding"""
    print("=" * 60)
    print("HUFFMAN CODING DEMO")
    print("=" * 60)
    
    # Test cases yang menarik
    test_cases = [
        "hello world",
        "aabbbcccc",
        "mississippi",
        "The quick brown fox jumps over the lazy dog",
        "aaaaaaaaaa",  # Edge case: semua karakter sama
        "abc",  # Edge case: semua karakter berbeda
    ]
    
    huffman = HuffmanCoding()
    
    for i, text in enumerate(test_cases, 1):
        print(f"\n{'='*20} TEST CASE {i} {'='*20}")
        print(f"Original text: '{text}'")
        print(f"Length: {len(text)} characters")
        
        # Encode
        encoded_text, freq_table = huffman.encode(text)
        print(f"Encoded text: {encoded_text}")
        print(f"Encoded length: {len(encoded_text)} bits")
        
        # Compression ratio
        ratio = huffman.get_compression_ratio(text, encoded_text)
        print(f"Compression ratio: {ratio:.2f}%")
        
        # Print frequency table
        print(f"\nFrequency table:")
        for char, freq in sorted(freq_table.items()):
            char_display = f"'{char}'" if char != ' ' else "' '"
            print(f"  {char_display}: {freq}")
        
        # Print Huffman codes
        huffman.print_codes()
        
        # Decode dan verify
        decoded_text = huffman.decode(encoded_text, freq_table)
        print(f"\nDecoded text: '{decoded_text}'")
        print(f"Decoding successful: {text == decoded_text}")
        
        # Visualize tree untuk test case pertama
        if i == 1:
            print(f"\nHuffman Tree Visualization:")
            huffman.visualize_tree()


def interactive_mode():
    """Mode interaktif untuk testing"""
    print("\n" + "="*60)
    print("INTERACTIVE HUFFMAN CODING")
    print("="*60)
    
    huffman = HuffmanCoding()
    
    while True:
        print("\nOptions:")
        print("1. Encode text")
        print("2. Decode text")
        print("3. Run demo")
        print("4. Exit")
        
        choice = input("\nEnter your choice (1-4): ").strip()
        
        if choice == "1":
            text = input("Enter text to encode: ")
            if text:
                encoded_text, freq_table = huffman.encode(text)
                print(f"\nEncoded: {encoded_text}")
                print(f"Compression ratio: {huffman.get_compression_ratio(text, encoded_text):.2f}%")
                huffman.print_codes()
                
                # Simpan untuk decoding
                huffman._last_encoded = encoded_text
                huffman._last_freq_table = freq_table
        
        elif choice == "2":
            if hasattr(huffman, '_last_encoded'):
                decoded_text = huffman.decode(huffman._last_encoded, huffman._last_freq_table)
                print(f"\nDecoded: {decoded_text}")
            else:
                print("No encoded text available. Please encode first.")
        
        elif choice == "3":
            demo_huffman_coding()
        
        elif choice == "4":
            print("Goodbye!")
            break
        
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    # Run demo
    demo_huffman_coding()
    
    # Uncomment untuk mode interaktif
    # interactive_mode()
