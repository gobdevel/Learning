#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <memory>
#include <system_error>

#include "utils.h"
template <typename Key, typename Value>
class BTree {
private:
    struct Node {
        template <typename K, typename... V>
        Node(K&& key, V... value)
            : key(std::forward<K>(key)), value(std::forward<V...>(value...)) {}
        Key                   key;
        Value                 value;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };

public:
    using value_type = Node;
    using pointer    = std::unique_ptr<Node>;

    template <typename K, typename... V>
    std::error_code insert(K&& key, V... args) {
        static_assert(std::is_same_v<Key, remove_cv_ref_t<K>>, "Not same type");
        return insertImpl(root, std::forward<K>(key),
                          std::forward<V...>(args...));
    }

    void for_each_inorder() {
        for_each_inorder_impl(root, [](const auto& key, const auto& value) {
            std::cout << "[ " << key << ", " << value << " ] ";
        });
        std::cout << "\n";
    }

    template <typename K>
    std::error_code remove(K&& key) {
        static_assert(std::is_same_v<Key, remove_cv_ref_t<K>>, "Not same type");
        return removeImpl(root, std::forward<K>(key));
    }

    int getHeight() { return heightImpl(root); }

private:
    template <typename K, typename... V>
    std::error_code insertImpl(pointer& node, K&& key, V... args) {
        if (!node) {
            node = std::make_unique<Node>(std::forward<K>(key),
                                          std::forward<V...>(args...));
        } else {
            if (node->key < key) {
                insertImpl(node->left, std::forward<K>(key),
                           std::forward<V...>(args...));
            } else {
                insertImpl(node->right, std::forward<K>(key),
                           std::forward<V...>(args...));
            }
        }
        return std::error_code();
    }

    template <typename F>
    void for_each_inorder_impl(pointer& node, F&& f) {
        if (node) {
            for_each_inorder_impl(node->left, f);
            f(node->key, node->value);
            for_each_inorder_impl(node->right, f);
        }
    }

    template <typename K>
    std::error_code removeImpl(pointer& node, K&& key) {
        if (node) {
            if (node->key == key) {
                if (!node->left && !node->right) {  // Leaf node;
                    node.reset(nullptr);            // Remove
                } else if (!node->left && node->right) {
                    node.reset(node->right.release());
                } else if (node->left && !node->right) {
                    node.reset(node->left.release());
                } else {
                    auto& temp  = succesor(node->right);
                    node->key   = temp->key;
                    node->value = std::move(temp->value);
                    removeImpl(node->right,
                               temp->key);  // TODO need to work here
                }
            } else if (key < node->key) {
                removeImpl(node->left, std::forward<K>(key));
            } else {
                removeImpl(node->right, std::forward<K>(key));
            }
            std::cout << std::endl;
        }
        return std::error_code();
    }

    int heightImpl(pointer& node) {
        if (node) {
            auto left  = heightImpl(node->left);
            auto right = heightImpl(node->right);
            return (std::max(left, right) + 1);
        }
        return 0;
    }

    pointer& succesor(pointer& node) {
        if (node->left) {
            return succesor(node->left);
        }
        return node;
    }
    pointer root;
};

#endif
