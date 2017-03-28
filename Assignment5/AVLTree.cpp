//
//  AVLTree.cpp
//  Assignment5
//
//  Created by Jasmine Jans on 4/14/14.
//  Copyright (c) 2014 Jasmine Jans. All rights reserved.
//


#include "avltree.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree() : BinarySearchTree()
{
    
}

AVLTree::~AVLTree()
{

}

void  AVLTree::Insert(const ItemType& newItem)
{
    insertItem (mroot, newItem);
}

void AVLTree::insertItem(Node *& treeptr, const ItemType& newItem)
{
    
}

Node* AVLTree::rightRotation(Node* k1)
{
    Node* k2;
    k2 = k1->mrightptr;
    k1->mrightptr = k2->mleftptr;
    k2->mleftptr = k1;
    return k2;
}

Node* AVLTree::leftRotation(Node* k2)
{
    Node* k1;
    k1 = k2->mrightptr;
    k2->mleftptr = k1->mrightptr;
    k1->mrightptr = k2;
    return k1;
}


