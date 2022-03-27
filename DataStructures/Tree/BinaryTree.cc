#include "BinaryTree.h"

#include <algorithm>
#include <iostream>

// INSERT
void  BinaryTree::insert(int value) { m_root = insert(m_root, value); }
Node* BinaryTree::insert(Node* node, int value) {
    if (!node) {
        node = new Node(value);
    } else {
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
    }
    return node;
}

int BinaryTree::getHeight() { return getHeight(m_root); }

int BinaryTree::getHeight(Node* node) {
    if (node) {
        return std::max(getHeight(node->left), getHeight(node->right)) + 1;
    }
    return 0;
}

Node* getInorderSuccessor(Node* node) {
    if (!node->left && !node->right) {
        return node;
    }
    return getInorderSuccessor(node->left);
}
// Remove
void BinaryTree::remove(int value) { m_root = remove(m_root, value); }

Node* BinaryTree::remove(Node* node, int value) {
    if (node) {
        if (value > node->value) {
            node->right = remove(node->right, value);
        } else if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value == node->value) {  // Node found
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                delete (node);
                return temp;
            } else {  // Both present
                Node* temp  = getInorderSuccessor(node->right);
                node->value = temp->value;
                node->right = remove(node->right, temp->value);
            }
        }
    }
    return node;
}
