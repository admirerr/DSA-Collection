#  C++ Folder Guide — DSA Collection

Welcome to the **C++** section of the DSA-Collection repository!  
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


Each folder contains one or more `.cpp` files implementing specific problems.

---

##  How to Compile and Run a C++ File

To compile and execute C++ programs, make sure you have a **C++ compiler** installed (e.g., `g++`, part of GCC).  
You can check your version by running:

```bash
g++ --version

Steps:

1️ Navigate to the directory of your desired file

cd CPP/sorting


2️ Compile the file

g++ filename.cpp -o output


For modern C++ features, use:

g++ -std=c++17 filename.cpp -o output


3️ Run the program

./output

Example:
g++ quick_sort.cpp -o quick_sort
./quick_sort