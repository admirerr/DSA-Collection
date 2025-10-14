/*
Huffman Coding Implementation in C++
===================================

Huffman coding adalah algoritma kompresi lossless yang menggunakan frekuensi karakter
untuk membuat kode biner yang optimal. Karakter yang sering muncul mendapat kode pendek,
sedangkan karakter jarang mendapat kode panjang.

Kompleksitas:
- Time: O(n log n) untuk membangun tree
- Space: O(n) untuk menyimpan frequency table dan codes

Author: [Your Name]
Date: 2024
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Node untuk Huffman Tree
struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    
    HuffmanNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
    
    // Constructor untuk internal nodes
    HuffmanNode(int freq, HuffmanNode* left, HuffmanNode* right) 
        : data('\0'), freq(freq), left(left), right(right) {}
};

// Comparator untuk priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq; // Min heap
    }
};

class HuffmanCoding {
private:
    unordered_map<char, string> codes;
    unordered_map<string, char> reverseCodes;
    HuffmanNode* root;
    
    // Helper function untuk membangun frequency table
    unordered_map<char, int> buildFrequencyTable(const string& text) {
        unordered_map<char, int> freqTable;
        for (char c : text) {
            freqTable[c]++;
        }
        return freqTable;
    }
    
    // Membangun Huffman Tree
    HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& freqTable) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;
        
        // Buat nodes untuk setiap karakter
        for (auto& pair : freqTable) {
            minHeap.push(new HuffmanNode(pair.first, pair.second));
        }
        
        // Bangun tree dengan menggabungkan nodes dengan frekuensi terendah
        while (minHeap.size() > 1) {
            HuffmanNode* left = minHeap.top();
            minHeap.pop();
            
            HuffmanNode* right = minHeap.top();
            minHeap.pop();
            
            // Buat internal node baru
            HuffmanNode* merged = new HuffmanNode(left->freq + right->freq, left, right);
            minHeap.push(merged);
        }
        
        return minHeap.top();
    }
    
    // Generate kode biner untuk setiap karakter (DFS traversal)
    void generateCodes(HuffmanNode* node, string currentCode = "") {
        if (node == nullptr) return;
        
        // Jika ini leaf node (memiliki karakter)
        if (node->data != '\0') {
            if (currentCode.empty()) { // Edge case: hanya 1 karakter
                currentCode = "0";
            }
            codes[node->data] = currentCode;
            reverseCodes[currentCode] = node->data;
            return;
        }
        
        // Traverse ke kiri (tambah "0")
        generateCodes(node->left, currentCode + "0");
        // Traverse ke kanan (tambah "1")
        generateCodes(node->right, currentCode + "1");
    }
    
    // Helper untuk cleanup memory
    void deleteTree(HuffmanNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
    
public:
    HuffmanCoding() : root(nullptr) {}
    
    ~HuffmanCoding() {
        deleteTree(root);
    }
    
    // Encode text menggunakan Huffman coding
    pair<string, unordered_map<char, int>> encode(const string& text) {
        if (text.empty()) {
            return make_pair("", unordered_map<char, int>());
        }
        
        // Reset previous state
        codes.clear();
        reverseCodes.clear();
        deleteTree(root);
        
        // Build frequency table
        unordered_map<char, int> freqTable = buildFrequencyTable(text);
        
        // Handle edge case: hanya 1 karakter unik
        if (freqTable.size() == 1) {
            char c = freqTable.begin()->first;
            codes[c] = "0";
            reverseCodes["0"] = c;
            string encodedText(freqTable[c], '0');
            return make_pair(encodedText, freqTable);
        }
        
        // Build Huffman tree
        root = buildHuffmanTree(freqTable);
        
        // Generate codes
        generateCodes(root);
        
        // Encode text
        string encodedText;
        for (char c : text) {
            encodedText += codes[c];
        }
        
        return make_pair(encodedText, freqTable);
    }
    
    // Decode text dari Huffman coding
    string decode(const string& encodedText, const unordered_map<char, int>& freqTable) {
        if (encodedText.empty()) return "";
        
        // Rebuild Huffman tree dari frequency table
        codes.clear();
        reverseCodes.clear();
        deleteTree(root);
        
        // Handle edge case: hanya 1 karakter unik
        if (freqTable.size() == 1) {
            char c = freqTable.begin()->first;
            codes[c] = "0";
            reverseCodes["0"] = c;
            return string(freqTable.at(c), c);
        }
        
        // Rebuild tree
        root = buildHuffmanTree(freqTable);
        generateCodes(root);
        
        // Decode text
        string decodedText;
        string currentCode;
        
        for (char bit : encodedText) {
            currentCode += bit;
            if (reverseCodes.find(currentCode) != reverseCodes.end()) {
                decodedText += reverseCodes[currentCode];
                currentCode.clear(); // Reset untuk karakter berikutnya
            }
        }
        
        return decodedText;
    }
    
    // Hitung compression ratio
    double getCompressionRatio(const string& originalText, const string& encodedText) {
        int originalBits = originalText.length() * 8; // ASCII = 8 bits per char
        int encodedBits = encodedText.length();
        return (1.0 - (double)encodedBits / originalBits) * 100.0;
    }
    
    // Print semua kode Huffman
    void printCodes() {
        cout << "\nHuffman Codes:" << endl;
        cout << string(30, '-') << endl;
        
        // Sort untuk output yang konsisten
        vector<pair<char, string>> sortedCodes(codes.begin(), codes.end());
        sort(sortedCodes.begin(), sortedCodes.end());
        
        for (auto& pair : sortedCodes) {
            char c = pair.first;
            string code = pair.second;
            
            if (c == '\n') {
                cout << "'\\n': " << code << endl;
            } else if (c == ' ') {
                cout << "' ': " << code << endl;
            } else {
                cout << "'" << c << "': " << code << endl;
            }
        }
    }
    
    // Visualisasi Huffman tree (recursive)
    void visualizeTree(HuffmanNode* node = nullptr, string prefix = "", bool isLast = true) {
        if (node == nullptr) {
            node = root;
        }
        
        if (node == nullptr) return;
        
        // Print current node
        string connector = isLast ? "└── " : "├── ";
        if (node->data != '\0') {
            string charDisplay = (node->data == ' ') ? "' '" : "'" + string(1, node->data) + "'";
            cout << prefix << connector << charDisplay << " (freq: " << node->freq << ")" << endl;
        } else {
            cout << prefix << connector << "Internal (freq: " << node->freq << ")" << endl;
        }
        
        // Print children
        if (node->left != nullptr || node->right != nullptr) {
            string newPrefix = prefix + (isLast ? "    " : "│   ");
            
            if (node->right != nullptr) {
                visualizeTree(node->right, newPrefix, node->left == nullptr);
            }
            if (node->left != nullptr) {
                visualizeTree(node->left, newPrefix, true);
            }
        }
    }
};

// Demo function
void demoHuffmanCoding() {
    cout << string(60, '=') << endl;
    cout << "HUFFMAN CODING DEMO" << endl;
    cout << string(60, '=') << endl;
    
    vector<string> testCases = {
        "hello world",
        "aabbbcccc",
        "mississippi",
        "The quick brown fox jumps over the lazy dog",
        "aaaaaaaaaa",  // Edge case: semua karakter sama
        "abc"          // Edge case: semua karakter berbeda
    };
    
    HuffmanCoding huffman;
    
    for (int i = 0; i < testCases.size(); i++) {
        cout << "\n" << string(20, '=') << " TEST CASE " << (i + 1) << " " << string(20, '=') << endl;
        string text = testCases[i];
        cout << "Original text: '" << text << "'" << endl;
        cout << "Length: " << text.length() << " characters" << endl;
        
        // Encode
        auto result = huffman.encode(text);
        string encodedText = result.first;
        unordered_map<char, int> freqTable = result.second;
        
        cout << "Encoded text: " << encodedText << endl;
        cout << "Encoded length: " << encodedText.length() << " bits" << endl;
        
        // Compression ratio
        double ratio = huffman.getCompressionRatio(text, encodedText);
        cout << "Compression ratio: " << fixed << setprecision(2) << ratio << "%" << endl;
        
        // Print frequency table
        cout << "\nFrequency table:" << endl;
        vector<pair<char, int>> sortedFreq(freqTable.begin(), freqTable.end());
        sort(sortedFreq.begin(), sortedFreq.end());
        
        for (auto& pair : sortedFreq) {
            char c = pair.first;
            int freq = pair.second;
            if (c == ' ') {
                cout << "  ' ': " << freq << endl;
            } else {
                cout << "  '" << c << "': " << freq << endl;
            }
        }
        
        // Print Huffman codes
        huffman.printCodes();
        
        // Decode dan verify
        string decodedText = huffman.decode(encodedText, freqTable);
        cout << "\nDecoded text: '" << decodedText << "'" << endl;
        cout << "Decoding successful: " << (text == decodedText ? "true" : "false") << endl;
        
        // Visualize tree untuk test case pertama
        if (i == 0) {
            cout << "\nHuffman Tree Visualization:" << endl;
            huffman.visualizeTree();
        }
    }
}

int main() {
    // Run demo
    demoHuffmanCoding();
    
    cout << "\n" << string(60, '=') << endl;
    cout << "INTERACTIVE MODE" << endl;
    cout << string(60, '=') << endl;
    
    HuffmanCoding huffman;
    string lastEncoded;
    unordered_map<char, int> lastFreqTable;
    
    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Encode text" << endl;
        cout << "2. Decode text" << endl;
        cout << "3. Run demo" << endl;
        cout << "4. Exit" << endl;
        
        int choice;
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter text to encode: ";
            cin.ignore(); // Clear input buffer
            string text;
            getline(cin, text);
            
            if (!text.empty()) {
                auto result = huffman.encode(text);
                lastEncoded = result.first;
                lastFreqTable = result.second;
                
                cout << "\nEncoded: " << lastEncoded << endl;
                cout << "Compression ratio: " << fixed << setprecision(2) 
                     << huffman.getCompressionRatio(text, lastEncoded) << "%" << endl;
                huffman.printCodes();
            }
        }
        else if (choice == 2) {
            if (!lastEncoded.empty()) {
                string decodedText = huffman.decode(lastEncoded, lastFreqTable);
                cout << "\nDecoded: " << decodedText << endl;
            } else {
                cout << "No encoded text available. Please encode first." << endl;
            }
        }
        else if (choice == 3) {
            demoHuffmanCoding();
        }
        else if (choice == 4) {
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}
