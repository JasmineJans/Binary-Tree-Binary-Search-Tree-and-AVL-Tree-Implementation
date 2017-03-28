//
//  bstTest.cpp
//
//    Assignment 5
//    Jasmine Jans
//    03/22/14

#include <iostream>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
    cout<<"TESTING FOR REGULAR BINARY TREE"<<endl;
    BinaryTree* tree1 = new BinaryTree();
    // test default constructor....tree1->inorderTraverse();
    BinaryTree* tree2 = new BinaryTree(3);
    // test one parameter constructor....tree2->inorderTraverse();
    BinaryTree* tree3 = new BinaryTree(6);
    // test one parameter constructor....tree3->inorderTraverse();
    BinaryTree* tree4 = new BinaryTree(12, *tree2, *tree3);
    cout<<endl;
    cout<<"inorder traverse of tree4"<<endl;
    tree4->inorderTraverse();
    
    //test constructors and inordertraverse funtion of BinaryTree class
    BinaryTree* tree5 = new BinaryTree(17);
    BinaryTree* tree6 = new BinaryTree(9);
    BinaryTree* tree7 = new BinaryTree(14, *tree5, *tree6);
    cout<<endl;
    cout<<"inorder traverse of tree7"<<endl;
    tree7->inorderTraverse();
    
    //test traversals and contructor of BinaryTree class
    cout<<endl;
    cout<<"newly made binary tree MAINTREE made with tree4 and tree7 with root 26"<<endl;
    BinaryTree* const mainTree = new BinaryTree(26, *tree4, *tree7);
    cout<<"inorder ";
    mainTree->inorderTraverse();
    cout<<"postorder ";
    mainTree->postorderTraverse();
    cout<<"preorder ";
    mainTree->preorderTraverse();
    
    //test copy constructor of BinaryTree class
    cout<<endl;
    cout<<"copied tree of maintree"<<endl;
    BinaryTree* copyTree = new BinaryTree(*mainTree);
    cout<<"inorder ";
    copyTree->inorderTraverse();
    cout<<"postorder ";
    copyTree->postorderTraverse();
    cout<<"preorder ";
    copyTree->preorderTraverse();
    
    
    
    cout<<endl;
    cout<<"TESTING FOR BINARY SEARCH TREE"<<endl;
    BinarySearchTree* bst1 = new BinarySearchTree();
    //test insert function in BinarySearchTree
    bst1->Insert(12);
    bst1->inorderTraverse();
    bst1->Insert(15);
    bst1->inorderTraverse();
    bst1->Insert(5);
    bst1->inorderTraverse();
    bst1->Insert(46);
    bst1->inorderTraverse();
    bst1->Insert(7);
    bst1->inorderTraverse();
    bst1->Insert(3);
    bst1->inorderTraverse();
    bst1->Insert(18);
    bst1->inorderTraverse();
    bst1->Insert(2);
    bst1->inorderTraverse();
    bst1->Insert(99);
    bst1->inorderTraverse();
    bst1->Insert(31);
    bst1->inorderTraverse();
    bst1->Insert(6);
    bst1->inorderTraverse();
    
    //test search function in BinarySearchTree
    cout<< endl;
    cout<< "search for number 5 (print 1) -> " << bst1->Search(5) <<endl;
    cout<< "search for number 19 (print error message) -> " << bst1->Search(19) <<endl;
    cout<< "search for number 46 (print 1) -> " << bst1->Search(46) <<endl;
    cout<< "search for number 1 (print error message) -> " << bst1->Search(1) <<endl;
    
    //test min and max lookup
    cout<< endl;
    cout<< (bst1->FindMin()) <<endl;
    cout<< bst1->FindMax() <<endl;
    
    //test remove function in BinarySearchTree
    cout<<endl;

    
    cout<< endl;
    bst1->remove(7);
    bst1->inorderTraverse();
    
    cout<<endl;
    bst1->remove(2);
    bst1->inorderTraverse();
    
    cout<<endl;
    bst1->remove(12);
    bst1->inorderTraverse();
    
    cout<<endl;
    bst1->remove(18);
    bst1->inorderTraverse();
    
    cout<<endl;
    bst1->remove(15);
    bst1->inorderTraverse();
    
    cout<<endl;
    bst1->remove(99);
    bst1->inorderTraverse();
    
    cout<<endl;
    bst1->remove(5);
    bst1->inorderTraverse();
    
}

