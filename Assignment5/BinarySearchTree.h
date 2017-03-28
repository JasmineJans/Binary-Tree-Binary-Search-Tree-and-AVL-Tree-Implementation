// Specification of ADT Binary Search Tree
//    Data object: A binary search tree T that is either empty or in the form
//    of a tree where each node has access to a left and right side off
//    of that node. The left side always contains a node with a value less than the root
//    and the right side node always contains a node with value greater than the root.
//    When a bunch of these roots with left and right nodes are are put together it makes
//    the shape of a tree.

//    Operations: (a scaled-down version)
//       all operations of the BinaryTree (parent class)
//       insert and search. inserts a key or looks for a key.
// Contract: this class can access private data members of class cnode.
//    Those data members are: citem mitem, cnode* mleftptr, cnode* mrightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.
//
//    Assignment 5
//    Jasmine Jans
//    03/22/14

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"
#include "node.h"

class BinarySearchTree: public BinaryTree
{
public:
    //@creates a new binary search tree
    //@post: an empty binary search tree object exists
    //@usage: BinarySearchTree bst;
    BinarySearchTree();
    
    //@releases memory for a binary search tree
    //@pre: binary search tree object exists
    //@post: binary search tree object does not exist
    //@usage: automatically done at end of scope
    ~BinarySearchTree();
    
    // *****************************************************************
    // *  pre for all member functions: binary search tree object exists
    // *****************************************************************
    
    //@searches for a key in a binary search tree object and
    //    retrieves the corresponding item
    //@pre: key has been assigned.
    //@post: theItem contains tkey with rest of the item if
    //    tkey is found in the binary search tree object
    //    else an exception is thrown
    //@usage: bst.Retrieve (abbrev, meaning);
    bool Search (const ItemType& theItem) const;
    
    //@inserts a new item into the binary search tree
    //@pre: newItem has been assigned
    //@post: if the newItem's key is not already in the tree
    //       and there is memory available
    //         then the newItem is added to the tree
    //       else an exception is thrown
    //@usage: you do
    void Insert (const ItemType& newItem);
    
    //@removes an item from the binary search tree
    //@pre: theItem has been assigned
    //@post: if theItem is in the tree
    //       then the node with that item is
    //        removed from the tree
    //       else the method just returns and ends and nothing is removed.
    //@usage: remove(mroot, mitem)
    void remove (const ItemType& theItem);
    
    //@finds the min item from the binary search tree
    //@pre: none.
    //@post: the min value in the tree is returned.
    //@usage: findMin()
    ItemType FindMin() const;
    
    //@finds the max item from the binary search tree
    //@pre: none.
    //@post: the max value in the tree is returned.
    //@usage: findMax()
    ItemType FindMax() const;
    
protected:  // recursive helper functions
    //@recursively searches (modeling on binary search) for a key
    //@pre: treeptr is assigned. newItem is assigned.
    //@post: searches for tkey in the tree with treeptr's root.
    //    If tkey is found, theItem is the key together with the other
    //    parts of the item. Else an exception is thrown.
    //@usage: retrieveItem (mroot, key, rest);
    bool lookup (Node * treeptr, const ItemType& theItem) const;
    
    //@recursively inserts an item in the correct place
    //@pre: treeptr is assigned. newItem is assigned.
    //@post: inserts the newItem in the tree with treeptr's root.
    //@usage: insertItem (mroot, mitem);
    void insertItem (Node *& treeptr, const ItemType& newItem);
    
    //@recursively removes an item from the tree
    //@pre: treeptr is assigned. theItem is assigned.
    //@post: removes theItem in the tree with treeptr's root.
    //@usage: removeItem (mroot, mitem);
    void removeItem (Node *& treeptr, const ItemType& theItem);
    
    //@recursively finds the minimum item in the tree
    //@pre: treeptr is assigned.
    //@post: returns the node in the tree that is the min.
    //@usage: lookforMin (mroot);
    Node * lookforMin(Node * treeptr) const;
    
    //@recursively finds the maximum item in the tree
    //@pre: treeptr is assigned.
    //@post: returns the node in the tree that is the max.
    //@usage: lookforMax (mroot);
    Node * lookforMax(Node * treeptr) const;
    
};
#endif