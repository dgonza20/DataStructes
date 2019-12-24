// David Gonzales
// Assignment 7
#include <string>
#include <iostream>
#include "bst.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
    root = nullptr;
}

// Recursive
void BinarySearchTree::insert(int key, string val){
    
    // Create a new node for the key and its value
    Node* new_node = new Node();
    new_node->key = key;
    new_node->val = val; 
    new_node->left = nullptr;
    new_node->right = nullptr;
    
    // If its the first node to be inserted make it the root node
    if(root == nullptr){
        root = new_node;
    }
    else{   // Call the helper to find out where to insert it into
        insertHelper(root, new_node);
    }
}

// Prints keys in-order. Recursive
void BinarySearchTree::printInOrder() const {
    printInOrderHelper(root); // Starting at the root of the BST Tree
}

//Returns value if node is present, else return empty string. Iterative
string BinarySearchTree::find(int key) const{
    
    // Node pointer to help look at the list of entires keys
    Node* current = root;
    
    // Go through the keys while we have not found the key or have not reached the nullptr
    while((current->key != key) || (current != nullptr)){
        
        // if the key passed in is the same as the current node being currently looked at
        if(key == current->key){
            // return that nodes value
            return current->val;
        }
        
        // If the key is less than the current node being looked at
        else if(key < current->key){
            // If the current key being looked at has no keys less than its current value, the key does not exist
            if(current->left == nullptr){
                return "";
            }
            else{   // Go left to check that nodes key
                current = current->left;
            }
        }
        
        // If the key is greater than the current node being looked at
        else if(key > current->key){
            // If the current key being looked at has no keys greater than its current value, the key does not exist
            if(current->right == nullptr){
                return "";
            }
            else{   // Go right to check that nodes key
                current = current->right;
            }
        }    
    }
    
}

void BinarySearchTree::insertHelper(Node* parent, Node* new_node){
    
    // If the key for the new node to insert is less than its parent's key 
    if(new_node->key <= parent->key){
        // If the parent has no left child, the new node becomes its left child
        if(parent->left == nullptr){
            parent->left = new_node;
        }
        else{   // Recursivly call the insertHelper to determine where to insert the new node
            insertHelper(parent->left, new_node);
        }
    } else{   // The new node key to insert is greater than its parent's key 
        // If the parent has no right child, the new node becomes its left child
        if(parent->right == nullptr){
            parent->right = new_node;
        }
        else{   // Recursivly call the insertHelper to determine where to insert the new node
            insertHelper(parent->right, new_node);
        }
    }
    
}

//Helper for recursive implemenation of printInroder()
void BinarySearchTree::printInOrderHelper(Node *n) const{
    
    // if there is a left child on the current node recursivley print the left side
    if(n->left !=  nullptr){
        printInOrderHelper(n->left);
    }
    
    // Print out the current node
    cout << "Key = " << n->key << " Element = " << n->val << endl;
    
    // If there is a right child on the current node recursivley print the right side
    if(n->right != nullptr){
        printInOrderHelper(n->right);
    }
    
}

