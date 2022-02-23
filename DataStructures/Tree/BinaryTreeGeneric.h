#ifndef __BINARY_TREE_GENERIC_H__
#define __BINARY_TREE_GENERIC_H__

#include <system_error>
#include <utility>

template <typename Key, typename Value>
class BinaryTree {
private:
    struct Node {
        template <typename K, typename... V>
        Node(K &&k, V... v)
            : key(std::forward<K>(k)), value{std::forward<V...>(v...)} {}
        Key   key;
        Value value;
        Node *left{nullptr};
        Node *right{nullptr};
    };
    Node *m_root{nullptr};

public:
    template <typename K, typename... V>
    BinaryTree &emplace(K &&key, V... value) {
        m_root =
            insert(m_root, std::forward<K>(key), std::forward<V...>(value...));
        return *this;
    }

    template <typename K>
    Value *find(K &&key) {
        return findInternal(m_root, std::forward<K>(key));
    }

private:
    template <typename K, typename... V>
    Node *insert(Node *node, K &&key, V... value) {
        if (!node) {
            node = new Node(std::forward<K>(key), std::forward<V...>(value...));
        } else {
            if (key < node->key) {
                node->left = insert(node->left, std::forward<K>(key),
                                    std::forward<V...>(value...));
            } else {
                node->right = insert(node->right, std::forward<K>(key),
                                     std::forward<V...>(value...));
            }
        }
        return node;
    }

    template <typename K>
    Value *findInternal(Node *node, K &&key) {
        if (!node) return nullptr;
        if (key == node->key) return &node->value;
        return (key > node->key
                    ? findInternal(node->right, std::forward<K>(key))
                    : findInternal(node->left, std::forward<K>(key)));
    }
};

#endif
