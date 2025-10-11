# C++ Folder Guide — DSA Collection

Welcome to the C++ section of the DSA-Collection repository!  
This guide explains how to compile and execute C++ files, follow naming conventions, and contribute effectively.

---

##  Folder Structure

Each folder below represents a category of data structures or algorithms:


```text
CPP/
├── Array/
├── Backtracking/
├── Basics/
├── BinarySearchTree/
├── Heap/
├── SystemDesign/
├── dynamic-programming/
├── graph/
├── linked-list/
├── pattern/
├── searching/
├── sorting/
├── strings/
├── tree-algorithm/
└── tree/

````

Each folder contains one or more `.cpp` files implementing specific problems.

---

##  How to Compile and Run a C++ File

To compile and execute C++ programs, make sure you have a **C++ compiler** installed (e.g., `g++`, part of GCC).  
You can check your version by running:

```bash
g++ --version
````

### 1️⃣ Navigate to the directory of your desired file

```bash
cd CPP/sorting
```

### 2️⃣ Compile the file

```bash
g++ filename.cpp -o output
```

For modern C++ features (e.g., C++17):

```bash
g++ -std=c++17 filename.cpp -o output
```

### 3️⃣ Run the program

```bash
./output
```

###  Example

```bash
g++ quick_sort.cpp -o quick_sort



