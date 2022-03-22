#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

struct Node {
    Node(int val) : value(val) {}
    int   value;
    Node *left{nullptr};
    Node *right{nullptr};
};

class BinaryTree {
public:
    void insert(int value);
    void remove(int value);
    void preOrder();
    void inOrder();
    void postOrder();
    int  getHeight();

private:
    Node *insert(Node *node, int value);
    Node *remove(Node *node, int value);
    void  preOrder(Node *node);
    void  inOrder(Node *node);
    void  postOrder(Node *node);
    int   getHeight(Node *node);
    Node *m_root{nullptr};
};

#endif
