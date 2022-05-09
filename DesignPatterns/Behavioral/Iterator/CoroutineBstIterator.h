#ifndef __COROUTINE_BST_ITERATOR_H__
#define __COROUTINE_BST_ITERATOR_H__

#include "BinaryTree.h"

std::generator<Node*> preOrderImpl(Node *node){
  if(node){
    for (auto x : preOrderImpl(node->left))
      std::co_yield x;

    for(auto y : preOrderImpl(node->right))
      std::co_yield y;

    std::co_yield node;
  }
}

#endif
