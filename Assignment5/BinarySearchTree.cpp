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

#include <iostream>
#include "binarysearchtree.h"
using namespace std;

//binarysearchtree.cpp

//@creates a new binary search tree
//@post: an empty binary search tree object exists
//@usage: BinarySearchTree bst;
BinarySearchTree:: BinarySearchTree(): BinaryTree()
{}

//@releases memory for a binary search tree
//@pre: binary search tree object exists
//@post: binary search tree object does not exist
//@usage: automatically done at end of scope
BinarySearchTree::~BinarySearchTree()
{
}

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
bool BinarySearchTree:: Search (const ItemType& theItem) const
{
    return lookup (mroot, theItem);
}

//@inserts a new item into the binary search tree
//@pre: newItem has been assigned
//@post: if the newItem's key is not already in the tree
//       and there is memory available
//         then the newItem is added to the tree
//       else an exception is thrown
//@usage: insert(mitem)
void BinarySearchTree:: Insert (const ItemType& newItem)
{
    insertItem (mroot, newItem);
}

//@recursively searches (modeling on binary search) for a key
//@pre: treeptr is assigned. newItem is assigned.
//@post: searches for tkey in the tree with treeptr's root.
//    If tkey is found, theItem is the key together with the other
//    parts of the item. Else an exception is thrown.
//@usage: lookup(mroot, theItem);
bool BinarySearchTree:: lookup (Node * treeptr, const ItemType& theItem) const
{
    if (treeptr == NULL)
    {
        cout<<"BinarySearchTree in lookup: key has not been found! "<<endl;
        return false;
    }
    else if (theItem == treeptr-> mitem)
        return true;
    else if (theItem < treeptr -> mitem)
        return lookup(treeptr->mleftptr, theItem);
    else
        return lookup(treeptr->mrightptr, theItem);
}


//@recursively inserts an item in the correct place
//@pre: treeptr is assigned. newItem is assigned.
//@post: inserts the newItem in the tree with treeptr's root.
//@usage: insertItem (mroot, mitem);
void BinarySearchTree:: insertItem (Node *& treeptr, const ItemType& newItem)
{
    if (treeptr == NULL)
        treeptr = new Node(newItem, NULL, NULL, 0);
    else if (newItem < treeptr -> mitem)
        insertItem(treeptr->mleftptr, newItem);
    else
        insertItem(treeptr->mrightptr, newItem);
}

//@removes an item from the binary search tree
//@pre: theItem has been assigned
//@post: if theItem is in the tree
//       then the node with that item is
//        removed from the tree
//       else the method just returns and ends and nothing is removed.
//@usage: remove(mroot, mitem)
void BinarySearchTree:: remove(const ItemType &theItem)
{
    removeItem(mroot, theItem);
}

//@recursively removes an item from the tree
//@pre: treeptr is assigned. theItem is assigned.
//@post: removes theItem in the tree with treeptr's root.
//@usage: removeItem (mroot, mitem);
void BinarySearchTree:: removeItem(Node* &treeptr, const ItemType& theItem)
{
    if(treeptr == NULL)
        return;
    else if(theItem > treeptr->mitem)
        removeItem(treeptr->mrightptr, theItem);
    else if(theItem < treeptr->mitem)
        removeItem(treeptr->mleftptr, theItem);
    else{
            if(treeptr->mleftptr != NULL && treeptr->mrightptr != NULL)
            {
                Node* temp = lookforMin(treeptr->mrightptr);
                treeptr->mitem = temp->mitem;
                removeItem(treeptr->mrightptr, treeptr->mitem);
            }
            else{
                treeptr = (treeptr->mleftptr != NULL)? treeptr->mleftptr : treeptr->mrightptr;
            }
        
        //code that could be used in place of line above^
        /* else if(treeptr->mleftptr == NULL && treeptr->mrightptr == NULL)
            {
                delete treeptr;
                treeptr = NULL;
            }
            else if(treeptr->mleftptr == NULL)
            {
                treeptr->mitem = treeptr->mrightptr->mitem;
                removeItem(treeptr->mrightptr, treeptr->mrightptr->mitem);
            }
            else if(treeptr->mrightptr == NULL)
            {
                treeptr->mitem = treeptr->mleftptr->mitem;
                removeItem(treeptr->mleftptr, treeptr->mleftptr->mitem);
            }
        */
    
    }
}



//@finds the max item from the binary search tree
//@pre: none.
//@post: the max value in the tree is returned.
//@usage: findMax()
ItemType BinarySearchTree::FindMax() const
{
    return lookforMax(mroot)->mitem;
}

//@finds the min item from the binary search tree
//@pre: none.
//@post: the min value in the tree is returned.
//@usage: findMin()
ItemType BinarySearchTree::FindMin() const
{
    return lookforMin(mroot)->mitem;
}

//@recursively finds the maximum item in the tree
//@pre: treeptr is assigned.
//@post: returns the node in the tree that is the max.
//@usage: lookforMax (mroot);
Node* BinarySearchTree::lookforMax(Node* treeptr) const
{
    if(treeptr == NULL)
        return NULL;
    if(treeptr->mrightptr == NULL)
        return treeptr;
    else
        return lookforMax(treeptr->mrightptr);
}

//@recursively finds the minimum item in the tree
//@pre: treeptr is assigned.
//@post: returns the node in the tree that is the min.
//@usage: lookforMin (mroot);
Node* BinarySearchTree::lookforMin(Node* treeptr) const
{
    if(treeptr == NULL)
        return NULL;
    if(treeptr->mleftptr == NULL)
        return treeptr;
    else
        return lookforMin(treeptr->mleftptr);
}