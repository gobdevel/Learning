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

    template <typename F>
    void preOrder(F &&f) {
        preOrder(f, m_root);
    }

    template <typename F>
    void inOrder(F &&f) {
        inOrder(f, m_root);
    }

    template <typename F>
    void postOrder(F &&f) {
        postOrder(f, m_root);
    }

    int getHeight();

private:
    Node *insert(Node *node, int value);
    Node *remove(Node *node, int value);

    template <typename F>
    void preOrder(F &&f, Node *node) {
        if (node) {
            f(node->value);
            preOrder(f, node->left);
            preOrder(f, node->right);
        }
    }

    template <typename F>
    void inOrder(F &&f, Node *node) {
        if (node) {
            inOrder(f, node->left);
            f(node->value);
            inOrder(f, node->right);
        }
    }

    template <typename F>
    void postOrder(F &&f, Node *node) {
        if (node) {
            postOrder(f, node->left);
            postOrder(f, node->right);
            f(node->value);
        }
    }

    int   getHeight(Node *node);
    Node *m_root{nullptr};
};

#endif
