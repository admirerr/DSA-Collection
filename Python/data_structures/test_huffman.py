#!/usr/bin/env python3
"""
Simple test untuk Huffman Coding implementation
"""

import sys
import os

# Add current directory to path
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from huffman_coding import HuffmanCoding

def test_basic_functionality():
    """Test basic encoding/decoding functionality"""
    print("Testing Huffman Coding Basic Functionality...")
    
    huffman = HuffmanCoding()
    
    # Test case 1: Simple text
    text1 = "hello"
    encoded1, freq1 = huffman.encode(text1)
    decoded1 = huffman.decode(encoded1, freq1)
    
    print(f"Test 1 - Original: '{text1}'")
    print(f"Test 1 - Encoded: {encoded1}")
    print(f"Test 1 - Decoded: '{decoded1}'")
    print(f"Test 1 - Success: {text1 == decoded1}")
    
    # Test case 2: Repeated characters
    text2 = "aaaabbbb"
    encoded2, freq2 = huffman.encode(text2)
    decoded2 = huffman.decode(encoded2, freq2)
    
    print(f"\nTest 2 - Original: '{text2}'")
    print(f"Test 2 - Encoded: {encoded2}")
    print(f"Test 2 - Decoded: '{decoded2}'")
    print(f"Test 2 - Success: {text2 == decoded2}")
    
    # Test case 3: Single character
    text3 = "aaaaa"
    encoded3, freq3 = huffman.encode(text3)
    decoded3 = huffman.decode(encoded3, freq3)
    
    print(f"\nTest 3 - Original: '{text3}'")
    print(f"Test 3 - Encoded: {encoded3}")
    print(f"Test 3 - Decoded: '{decoded3}'")
    print(f"Test 3 - Success: {text3 == decoded3}")
    
    # Test compression ratio
    ratio1 = huffman.get_compression_ratio(text1, encoded1)
    ratio2 = huffman.get_compression_ratio(text2, encoded2)
    ratio3 = huffman.get_compression_ratio(text3, encoded3)
    
    print(f"\nCompression Ratios:")
    print(f"Text 1: {ratio1:.2f}%")
    print(f"Text 2: {ratio2:.2f}%")
    print(f"Text 3: {ratio3:.2f}%")
    
    print("\nAll tests completed!")

if __name__ == "__main__":
    test_basic_functionality()
