/**
 * Huffman Coding Implementation in JavaScript
 * ==========================================
 * 
 * Huffman coding adalah algoritma kompresi lossless yang menggunakan frekuensi karakter
 * untuk membuat kode biner yang optimal. Karakter yang sering muncul mendapat kode pendek,
 * sedangkan karakter jarang mendapat kode panjang.
 * 
 * Kompleksitas:
 * - Time: O(n log n) untuk membangun tree
 * - Space: O(n) untuk menyimpan frequency table dan codes
 * 
 */

class HuffmanNode {
    constructor(data = null, freq = 0, left = null, right = null) {
        this.data = data;  // karakter (null untuk internal nodes)
        this.freq = freq;  // frekuensi
        this.left = left;  // child kiri
        this.right = right; // child kanan
    }
}

class HuffmanCoding {
    constructor() {
        this.codes = new Map();  // mapping karakter ke kode biner
        this.reverseCodes = new Map();  // mapping kode biner ke karakter
        this.root = null;  // root dari huffman tree
    }

    /**
     * Membangun tabel frekuensi karakter
     * @param {string} text - Text yang akan dianalisis
     * @returns {Map} Frequency table
     */
    _buildFrequencyTable(text) {
        const freqTable = new Map();
        for (const char of text) {
            freqTable.set(char, (freqTable.get(char) || 0) + 1);
        }
        return freqTable;
    }

    /**
     * Membangun Huffman Tree menggunakan priority queue
     * @param {Map} freqTable - Frequency table
     * @returns {HuffmanNode} Root node
     */
    _buildHuffmanTree(freqTable) {
        // Buat array untuk priority queue (min heap simulation)
        const heap = [];
        
        // Buat nodes untuk setiap karakter
        for (const [char, freq] of freqTable) {
            heap.push(new HuffmanNode(char, freq));
        }
        
        // Sort berdasarkan frekuensi (min heap)
        heap.sort((a, b) => a.freq - b.freq);
        
        // Bangun tree dengan menggabungkan nodes dengan frekuensi terendah
        while (heap.length > 1) {
            // Ambil 2 nodes dengan frekuensi terendah
            const left = heap.shift();
            const right = heap.shift();
            
            // Buat internal node baru
            const merged = new HuffmanNode(null, left.freq + right.freq, left, right);
            
            // Insert dengan urutan yang benar (binary search)
            let insertIndex = 0;
            while (insertIndex < heap.length && heap[insertIndex].freq < merged.freq) {
                insertIndex++;
            }
            heap.splice(insertIndex, 0, merged);
        }
        
        return heap[0]; // root node
    }

    /**
     * Generate kode biner untuk setiap karakter (DFS traversal)
     * @param {HuffmanNode} node - Current node
     * @param {string} currentCode - Current binary code
     */
    _generateCodes(node, currentCode = "") {
        if (!node) return;
        
        // Jika ini leaf node (memiliki karakter)
        if (node.data !== null) {
            if (currentCode === "") { // Edge case: hanya 1 karakter
                currentCode = "0";
            }
            this.codes.set(node.data, currentCode);
            this.reverseCodes.set(currentCode, node.data);
            return;
        }
        
        // Traverse ke kiri (tambah "0")
        this._generateCodes(node.left, currentCode + "0");
        // Traverse ke kanan (tambah "1")
        this._generateCodes(node.right, currentCode + "1");
    }

    /**
     * Encode text menggunakan Huffman coding
     * @param {string} text - Text yang akan di-encode
     * @returns {Object} {encodedText, freqTable}
     */
    encode(text) {
        if (!text) {
            return { encodedText: "", freqTable: new Map() };
        }
        
        // Reset previous state
        this.codes.clear();
        this.reverseCodes.clear();
        
        // Build frequency table
        const freqTable = this._buildFrequencyTable(text);
        
        // Handle edge case: hanya 1 karakter unik
        if (freqTable.size === 1) {
            const char = freqTable.keys().next().value;
            this.codes.set(char, "0");
            this.reverseCodes.set("0", char);
            const encodedText = "0".repeat(freqTable.get(char));
            return { encodedText, freqTable };
        }
        
        // Build Huffman tree
        this.root = this._buildHuffmanTree(freqTable);
        
        // Generate codes
        this._generateCodes(this.root);
        
        // Encode text
        let encodedText = "";
        for (const char of text) {
            encodedText += this.codes.get(char);
        }
        
        return { encodedText, freqTable };
    }

    /**
     * Decode text dari Huffman coding
     * @param {string} encodedText - Encoded text
     * @param {Map} freqTable - Frequency table
     * @returns {string} Decoded text
     */
    decode(encodedText, freqTable) {
        if (!encodedText) return "";
        
        // Rebuild Huffman tree dari frequency table
        this.codes.clear();
        this.reverseCodes.clear();
        
        // Handle edge case: hanya 1 karakter unik
        if (freqTable.size === 1) {
            const char = freqTable.keys().next().value;
            this.codes.set(char, "0");
            this.reverseCodes.set("0", char);
            return char.repeat(freqTable.get(char));
        }
        
        // Rebuild tree
        this.root = this._buildHuffmanTree(freqTable);
        this._generateCodes(this.root);
        
        // Decode text
        let decodedText = "";
        let currentCode = "";
        
        for (const bit of encodedText) {
            currentCode += bit;
            if (this.reverseCodes.has(currentCode)) {
                decodedText += this.reverseCodes.get(currentCode);
                currentCode = ""; // Reset untuk karakter berikutnya
            }
        }
        
        return decodedText;
    }

    /**
     * Hitung compression ratio
     * @param {string} originalText - Original text
     * @param {string} encodedText - Encoded text
     * @returns {number} Compression ratio percentage
     */
    getCompressionRatio(originalText, encodedText) {
        const originalBits = originalText.length * 8; // ASCII = 8 bits per char
        const encodedBits = encodedText.length;
        return (1 - encodedBits / originalBits) * 100;
    }

    /**
     * Print semua kode Huffman
     */
    printCodes() {
        console.log("\nHuffman Codes:");
        console.log("-".repeat(30));
        
        // Sort untuk output yang konsisten
        const sortedCodes = Array.from(this.codes.entries()).sort();
        
        for (const [char, code] of sortedCodes) {
            if (char === '\n') {
                console.log(`'\\n': ${code}`);
            } else if (char === ' ') {
                console.log(`' ': ${code}`);
            } else {
                console.log(`'${char}': ${code}`);
            }
        }
    }

    /**
     * Visualisasi Huffman tree (recursive)
     * @param {HuffmanNode} node - Current node
     * @param {string} prefix - Prefix untuk indentation
     * @param {boolean} isLast - Apakah ini node terakhir
     */
    visualizeTree(node = null, prefix = "", isLast = true) {
        if (!node) {
            node = this.root;
        }
        
        if (!node) return;
        
        // Print current node
        const connector = isLast ? "└── " : "├── ";
        if (node.data !== null) {
            const charDisplay = node.data === ' ' ? "' '" : `'${node.data}'`;
            console.log(`${prefix}${connector}${charDisplay} (freq: ${node.freq})`);
        } else {
            console.log(`${prefix}${connector}Internal (freq: ${node.freq})`);
        }
        
        // Print children
        if (node.left || node.right) {
            const newPrefix = prefix + (isLast ? "    " : "│   ");
            
            if (node.right) {
                this.visualizeTree(node.right, newPrefix, !node.left);
            }
            if (node.left) {
                this.visualizeTree(node.left, newPrefix, true);
            }
        }
    }

    /**
     * Convert Map to Object untuk JSON serialization
     * @param {Map} map - Map object
     * @returns {Object} Plain object
     */
    _mapToObject(map) {
        const obj = {};
        for (const [key, value] of map) {
            obj[key] = value;
        }
        return obj;
    }

    /**
     * Convert Object to Map dari JSON deserialization
     * @param {Object} obj - Plain object
     * @returns {Map} Map object
     */
    _objectToMap(obj) {
        const map = new Map();
        for (const [key, value] of Object.entries(obj)) {
            map.set(key, value);
        }
        return map;
    }

    /**
     * Serialize Huffman codes untuk storage
     * @returns {string} JSON string
     */
    serialize() {
        return JSON.stringify({
            codes: this._mapToObject(this.codes),
            reverseCodes: this._mapToObject(this.reverseCodes)
        });
    }

    /**
     * Deserialize Huffman codes dari storage
     * @param {string} jsonString - JSON string
     */
    deserialize(jsonString) {
        const data = JSON.parse(jsonString);
        this.codes = this._objectToMap(data.codes);
        this.reverseCodes = this._objectToMap(data.reverseCodes);
    }
}

/**
 * Demo function untuk Huffman Coding
 */
function demoHuffmanCoding() {
    console.log("=".repeat(60));
    console.log("HUFFMAN CODING DEMO");
    console.log("=".repeat(60));
    
    const testCases = [
        "hello world",
        "aabbbcccc",
        "mississippi",
        "The quick brown fox jumps over the lazy dog",
        "aaaaaaaaaa",  // Edge case: semua karakter sama
        "abc"          // Edge case: semua karakter berbeda
    ];
    
    const huffman = new HuffmanCoding();
    
    testCases.forEach((text, index) => {
        console.log(`\n${"=".repeat(20)} TEST CASE ${index + 1} ${"=".repeat(20)}`);
        console.log(`Original text: '${text}'`);
        console.log(`Length: ${text.length} characters`);
        
        // Encode
        const { encodedText, freqTable } = huffman.encode(text);
        console.log(`Encoded text: ${encodedText}`);
        console.log(`Encoded length: ${encodedText.length} bits`);
        
        // Compression ratio
        const ratio = huffman.getCompressionRatio(text, encodedText);
        console.log(`Compression ratio: ${ratio.toFixed(2)}%`);
        
        // Print frequency table
        console.log(`\nFrequency table:`);
        const sortedFreq = Array.from(freqTable.entries()).sort();
        sortedFreq.forEach(([char, freq]) => {
            const charDisplay = char === ' ' ? "' '" : `'${char}'`;
            console.log(`  ${charDisplay}: ${freq}`);
        });
        
        // Print Huffman codes
        huffman.printCodes();
        
        // Decode dan verify
        const decodedText = huffman.decode(encodedText, freqTable);
        console.log(`\nDecoded text: '${decodedText}'`);
        console.log(`Decoding successful: ${text === decodedText}`);
        
        // Visualize tree untuk test case pertama
        if (index === 0) {
            console.log(`\nHuffman Tree Visualization:`);
            huffman.visualizeTree();
        }
    });
}

/**
 * Interactive mode untuk testing
 */
function interactiveMode() {
    console.log("\n" + "=".repeat(60));
    console.log("INTERACTIVE HUFFMAN CODING");
    console.log("=".repeat(60));
    
    const huffman = new HuffmanCoding();
    let lastEncoded = "";
    let lastFreqTable = new Map();
    
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    
    function showMenu() {
        console.log("\nOptions:");
        console.log("1. Encode text");
        console.log("2. Decode text");
        console.log("3. Run demo");
        console.log("4. Exit");
        
        rl.question("\nEnter your choice (1-4): ", (choice) => {
            switch (choice.trim()) {
                case "1":
                    rl.question("Enter text to encode: ", (text) => {
                        if (text) {
                            const { encodedText, freqTable } = huffman.encode(text);
                            lastEncoded = encodedText;
                            lastFreqTable = freqTable;
                            
                            console.log(`\nEncoded: ${encodedText}`);
                            console.log(`Compression ratio: ${huffman.getCompressionRatio(text, encodedText).toFixed(2)}%`);
                            huffman.printCodes();
                        }
                        showMenu();
                    });
                    break;
                    
                case "2":
                    if (lastEncoded) {
                        const decodedText = huffman.decode(lastEncoded, lastFreqTable);
                        console.log(`\nDecoded: ${decodedText}`);
                    } else {
                        console.log("No encoded text available. Please encode first.");
                    }
                    showMenu();
                    break;
                    
                case "3":
                    demoHuffmanCoding();
                    showMenu();
                    break;
                    
                case "4":
                    console.log("Goodbye!");
                    rl.close();
                    break;
                    
                default:
                    console.log("Invalid choice. Please try again.");
                    showMenu();
                    break;
            }
        });
    }
    
    showMenu();
}

// Export untuk module usage
if (typeof module !== 'undefined' && module.exports) {
    module.exports = { HuffmanCoding, HuffmanNode };
}

// Run demo jika dijalankan langsung
if (typeof require !== 'undefined' && require.main === module) {
    demoHuffmanCoding();
    
    // Uncomment untuk mode interaktif
    // interactiveMode();
}
