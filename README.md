# DataStructures

### B-Tree   
B-Tree is a self-balancing search tree.  
The main idea of using B-Trees is to reduce the number of disk accesses.   
Most of the tree operations require O(h) disk accesses where h is the height of the tree.   
B-tree is a fat tree. refer https://www.geeksforgeeks.org/b-tree-set-1-introduction-2/ for more details on BTree.  
  
### Expression tree  
An Expression tree is a representation of expressions arranged in a tree-like data structure.   
In other words, it is a tree with leaves as operands of the expression and nodes contain the operators.  
Here, expression Tree is implemented in C++ Data structures and finally its value is calculated.
  
### AVL Tree  
AVL tree is a self-balancing Binary Search Tree (BST) where the difference between heights of left and right subtrees cannot be more than one for all nodes. https://www.geeksforgeeks.org/avl-tree-set-1-insertion/

### Huffman Coding  
Implementation of Huffman coding with binary trees in C++  
Huffman code is a type of optimal prefix code that is commonly used for lossless data compression.  
The main idea is to transform plain input into variable-length code. As in other entropy encoding methods, more common symbols are generally represented using fewer bits than less common symbols. The easiest way to understand how to create Huffman tree is to analyze following steps:  
1.Scan text for symbols (e.g. 1-byte characters) and calculate their frequency of occurrence.   
Symbol value with its count of occurrences is a single leaf.  
Start a loop.   
2.Find two smallest probability nodes and combine them into single node.  
3.Remove those two nodes from list and insert combined one.  
4.Repeat the loop until the list has only single node.  
5.This last single node represent a huffman tree.  
