//
//  AVLTree.h
//  Assignment5
//
//  Created by Jasmine Jans on 4/14/14.
//  Copyright (c) 2014 Jasmine Jans. All rights reserved.
//

#ifndef AVLTREE_H
#define AVLTREE_H

#include "binarysearchtree.h"
#include "node.h"

class AVLTree: public BinarySearchTree
{
    public:
    
    //@creates a new avl tree
    //@post: an empty binary search tree object exists
    //@usage: BinarySearchTree bst;
    AVLTree();
    
    //@releases memory for a avl tree
    //@pre: avl tree object exists
    //@post: avl tree object does not exist
    //@usage: automatically done at end of scope
    ~AVLTree();
    
    //@inserts a new item into the AVL tree
    //@pre: newItem has been assigned
    //@post: if the newItem's key is not already in the tree
    //       and there is memory available
    //         then the newItem is added to the tree
    //       else an exception is thrown
    //@usage: you do
    void Insert (const ItemType& newItem);
    
    //
    void printTest ();
    
    //
    Node* rightRotation(Node* k1);
    
    //
    Node* leftRotation(Node* k2);
    
    protected:
    
    //@recursively inserts an item in the correct place
    //@pre: treeptr is assigned. newItem is assigned.
    //@post: inserts the newItem in the tree with treeptr's root.
    //@usage: insertItem (mroot, mitem);
    void insertItem (Node *& treeptr, const ItemType& newItem);
};
#endif
