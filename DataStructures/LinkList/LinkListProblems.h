#ifndef __LINKLIST_PROBLEM_H__
#define __LINKLIST_PROBLEM_H__
#include "LinkListBasic.h"

template <typename T>
Node<T>* reverse(Node<T>* head) {
    Node<T>*prev = nullptr, *next = nullptr;
    while (head) {
        next       = head->next;
        head->next = prev;
        prev       = head;
        head       = next;
    }

    return prev;
}

#endif
