#ifndef __LINKLIST_BASIC_H__
#define __LINKLIST_BASIC_H__

#include <type_traits>
#include <utility>

#include "utils.h"
template <typename T>
struct Node {
    template <typename D>
    Node(D &&data) : val(std::forward<D>(data)), next(nullptr) {}

    template <typename D>
    Node(D &&data, Node *nextPtr) : val(std::forward<D>(data)), next(nextPtr) {}

    T     val;
    Node *next;
};

// Utility to convert LinkList to vector
template <typename T>
std::vector<T> convertLinkListToVector(Node<T> *root) {
    std::vector<T> res;
    while (root) {
        res.emplace_back(root->val);
        root = root->next;
    }
    return res;
}

template <typename T>
class LinkList {
public:
    using Node       = Node<T>;
    using VectorData = std::vector<T>;
    LinkList()       = default;

    std::size_t getSize() { return size; }
    Node       *getHead() { return head; }
    void        setHead(Node *ptr) { head = ptr; }

    template <typename D>
    LinkList &emplace_back(D &&value) {
        static_assert(std::is_same_v<T, remove_cv_ref_t<D>>, "Type not same");
        if (!head) {
            head = new Node(std::forward<D>(value));
        } else {
            Node *curr = head;
            while (curr && curr->next) {
                curr = curr->next;
            }
            curr->next = new Node(std::forward<D>(value));
        }
        ++size;
        return *this;
    }

    template <typename D>
    LinkList &emplace_front(D &&value) {
        static_assert(std::is_same_v<T, remove_cv_ref_t<D>>, "Type not same");
        head = new Node(std::forward<D>(value), head);
        ++size;
        return *this;
    }

    VectorData getVectorData() {
        VectorData data;
        Node      *curr = head;
        while (curr) {
            data.emplace_back(curr->val);
            curr = curr->next;
        }
        return data;
    }

    LinkList &delete_back() {
        if (head) {
            if (head->next == nullptr) {
                delete head;
                head = nullptr;
            } else {
                Node *curr = head;
                while (curr->next && curr->next->next) {
                    curr = curr->next;
                }
                delete (curr->next);
                curr->next = nullptr;
            }
            --size;
        }
        return *this;
    }

    LinkList &delete_front() {
        if (head) {
            Node *curr = head;
            head       = head->next;
            delete (curr);
            --size;
        }
        return *this;
    }

private:
    Node       *head{nullptr};
    std::size_t size{0};
};

#endif  //__LINKLIST_BASIC_H__
