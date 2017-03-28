//emilia hw help

#include <cstddef>

#ifndef NODE_H
#define NODE_H
typedef int ItemType;

template<class K, vlass V>
class Node: public Node<K,V>
{
public:
    
    // creates a node
    // post: the item of the node is empty and the kids are NULL
    // usage: newptr = new cnode();
    Node():mleftptr(NULL),mrightptr(NULL) {};
    
    // creates a node with a given item and kids
    // post: the item of the node is nodeItem, the kids are left and right
    // usage:aptr = new (nothrow) Node (thisone, NULL, NULL);
    // CAUTION: REQUIRES THAT COPY WORKS IN ItemType!!
    Node (const ItemType& nodeKey, const ItemType& value,
          Node* left, Node* right, int height):
    key (nodeItem), value (nodeItem), mleftptr (left), mrightptr (right), height (height) {}
    
    // implementation of data object
    //ItemType mitem;
privateL
    int height;
    K key
    V value;
    Node* mleftptr;
    Node* mrightptr;
};
#endif
