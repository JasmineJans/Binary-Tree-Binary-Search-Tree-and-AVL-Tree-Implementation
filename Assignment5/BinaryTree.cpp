// Specification of ADT Binary Tree
//    Data object: A binary tree T that is either empty or in the form
//    of a tree where each node has access to a left and right side off
//    of that node. When a bunch are put together it makes the shape of a tree.

//    Operations: (a scaled-down version)
//       create, destroy, copy, operator=,
//       traversals (preorder, inorder, postorder)
// Contract: Assumes the this class can access private data members of class cnode.
//    Those data members are: citem mitem, cnode* mleftptr, cnode* mrightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.

//
//    Assignment 5
//    Jasmine Jans
//    03/22/14
//

#include <iostream>
#include "binarytree.h"
using namespace std;

// creates an empty binary tree
// post: object is an empty binary tree
// usage: BinaryTree zags;
BinaryTree::BinaryTree(): mroot(NULL)
{
    mroot = NULL;
}

//constructor that takes one parameter fr root value
BinaryTree::BinaryTree(const ItemType& rootItem)
{
    mroot = new Node(rootItem, NULL, NULL, 0);
}

//constructor that takes 3 params. root value and left and right trees.
BinaryTree::BinaryTree(const ItemType& rootItem, BinaryTree& leftTree, BinaryTree& rightTree)
{
    mroot = new Node(rootItem, NULL, NULL, 0);
    mroot-> mleftptr=leftTree.mroot;
    mroot-> mrightptr=rightTree.mroot;
    leftTree.mroot=NULL;
    rightTree.mroot=NULL;
}

// creates a new binary tree that is a copy of an existing tree
// post: object is a copy of rhstree
// usage: BinaryTree zags (bulldog);
BinaryTree::BinaryTree(const BinaryTree& rhstree)
{
    copyTree (mroot, rhstree.mroot);
}

// releases the memory of a binary tree
// pre: object exists
// post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinaryTree:: ~BinaryTree()
{
    destroyTree(mroot);
}

// ******************** member functions ********************************************
// pre: binary tree object exists
// **********************************************************************************
// post: returns true if the object is empty; else returns false
// usage: if (tree.isEmpty())
bool BinaryTree::IsEmpty() const
{
    return mroot==NULL;
}


/*
 // pre: rhstree is an assigned tree.
 // post: object is a copy of rhstree
 // usage: atree = btree = ctree;
 BinaryTree& BinaryTree::operator=(const BinaryTree& rhstree)
 {
 if (this != &rhstree)
 {
 destroyTree(mroot);
 copyTree (mroot, rhstree.mroot);
 }
 return *this;
 }
 */


// Add prettyDisplay and writePretty from the .h file

// *************** on the following traversals
// uses: operator<< from citem
// post: prints the objects in the tree in order specified
// usage: tree.preorderTraverse();
// similarly for the other traversals
// *****************************************************

//traverses tree and prints in pre order
void BinaryTree::preorderTraverse () const
{
    preorder(mroot);
    cout<<endl;
}

//traverses tree and prints in in order
void BinaryTree::inorderTraverse () const
{
    inorder(mroot);
    cout<<endl;
}

//traverses tree and prints in post order
void BinaryTree::postorderTraverse() const
{
    postorder(mroot);
    cout<<endl;
}


// makes a tree for testing purposes. You may add a file parameter
// post: the tree is a full tree of height 2
// usage: mytree.makeTree();

/*
 void BinaryTree:: makeTree()
 {
 // YOU CODE
 }
 
 */
// helper functions for coding member functions


// Copies one binary tree to another
// pre: oldtreep points to the root of a binary tree
// post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
// usage: copyTree (newptr, oldptr);
void BinaryTree::copyTree (Node*& newtreep, Node* oldtreep)
{
    if (oldtreep == NULL)
        newtreep = NULL;
    else
    {
        newtreep = new Node(oldtreep->mitem, NULL, NULL, 0);
        copyTree(newtreep->mleftptr, oldtreep->mleftptr);
        copyTree(newtreep->mrightptr, oldtreep->mrightptr);
    }
}

// Releases memory for a binary tree
// pre: treep points to the root of a binary tree
// post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
// usage: destroyTree (mroot);
void BinaryTree::destroyTree (Node*& treep)
{
    // do a postorder traversal
    if (treep != NULL)
    {
        destroyTree(treep->mleftptr);
        destroyTree(treep->mrightptr);
        treep = NULL;
    }
}

// ********** recursive helpers for the traversals ****************
// pre: treep points to the root of a binary tree to be traversed
// post: prints the objects of the nodes on the screen in the
// specified order
// usage: preorder (mroot);
//    similarly for the others
void BinaryTree::preorder (Node* treep) const
{
    if (treep != NULL)
    {
        cout <<  treep -> mitem << "  ";
        preorder (treep -> mleftptr);
        preorder (treep -> mrightptr);
    }
}
void BinaryTree::inorder (Node* treep) const
{
    if (treep != NULL)
    {
        inorder (treep -> mleftptr);
        cout <<  treep -> mitem << "  ";
        inorder (treep -> mrightptr);
    }
    
}
void BinaryTree::postorder (Node* treep) const
{
    if (treep != NULL)
    {
        postorder (treep -> mleftptr);
        postorder (treep -> mrightptr);
        cout <<  treep -> mitem << "  ";
    }
    
}

