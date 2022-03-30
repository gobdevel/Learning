#ifndef __LINK_LIST_TEMPLATE_H__
#define __LINK_LIST_TEMPLATE_H__

#include <algorithm>
#include <iterator>
#include <system_error>

template <typename T>
struct ListNode {
    template <typename... Args>
    ListNode(Args &&...args)
        : val(std::forward<Args...>(args...)), next(nullptr) {}
    T         val;
    ListNode *next;
};

template <typename T>
class ForwardList {
    using Node = ListNode<T>;

public:
    struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = Node;
        using pointer           = value_type *;
        using reference         = value_type &;

        Iterator(pointer ptr) : m_ptr(ptr) {}
        reference operator*() { return *m_ptr; }
        pointer   operator->() { return m_ptr; }

        // Prefix
        Iterator &operator++() {
            m_ptr = m_ptr->next;
            return *this;
        }
        // Postfix
        Iterator operator++(int) {
            auto old = *this;
            ++(*this);
            return old;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) {
            return a.m_ptr == b.m_ptr;
        }

        friend bool operator!=(const Iterator &a, const Iterator &b) {
            return a.m_ptr != b.m_ptr;
        }

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    Iterator find(const T &key) {
        for (auto i = head; i != nullptr; i = i->next) {
            if (i->val == key) {
                return Iterator(i);
            }
        }
        return end();
    }

    template <typename... Args>
    std::error_code emplace_back(Args &&...args) {
        if (head == nullptr) {
            head = new Node(std::forward<Args...>(args...));
            assert(head);
            tail = head;
        } else {
            tail->next = new Node(std::forward<Args...>(args...));
            assert(tail->next);
            tail = tail->next;
        }
        return std::error_code();
    }

    template <typename... Args>
    std::error_code emplace_front(Args &&...args) {
        if (head == nullptr) {
            head = new Node(std::forward<Args...>(args...));
            assert(head);
            tail = head;
        } else {
            auto next = head;
            head      = new Node(std::forward<Args...>(args...));
            assert(head);
            head->next = next;
        }
        return std::error_code();
    }

    void remove_first() {
        if (head) {
            auto toDel = head;
            head       = head->next;
            tail       = head ? tail : head;  // if only single element
            delete (toDel);
        }
    }

    void remove_last() {
        if (!head) return;
        if (head == tail) {
            delete (head);
            head = tail = nullptr;
            return;
        }
        Node *curr = head;
        while (curr && curr->next && curr->next->next) {
            curr = curr->next;
        }
        delete (curr->next);
        curr->next = nullptr;
        tail       = curr;
    }

    template <typename F>
    void for_each(F &&f) {
        auto curr = head;
        while (curr) {
            f(curr->val);
            curr = curr->next;
        }
    }

private:
    Node *head{nullptr};
    Node *tail{nullptr};
};

#endif
