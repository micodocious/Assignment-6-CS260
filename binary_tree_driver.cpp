/*
Assignment 6 (Binary search tree)(two week assignment)
Mico Santiago

binary-tree_driver.cpp and binary_tree.cpp are code used to follow along to Binary Trees: Theory and C++ Implementation by Dr. Ahmad Bazzi to deepen
my understanding of binary trees. 


*/

#include <iostream>
#include "binary_tree.cpp"

using namespace std;

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    /*node *root = create_node(50);
    //cout << root->value << endl;

    root->left = create_node(25);
    root->left->left = create_node(15);

    root->right = create_node(75);
    root->right->right = create_node(90);
        //              50
        //             /  \ 
        //           25    75
        //          /        \ 
        //        15          90
    */
    
    //Test insert
    //without double pointers
    /*insert(&root,30);
        //              50
        //             /  \ 
        //           25    75
        //          /  \     \ 
        //        15    30    90
    cout << root->left->right->value << endl;*/


    //TEST Search function (Level Order Traversal)
    /*node *root = NULL;
    node *my_node = search(root, 11);
    cout << my_node->value << endl;*/
    
    //test insert function for BFT
    node *root = NULL;
    
    for(int i = 1; i <=6; i++)
        insert(&root,i);
        //              1
        //             /  \ 
        //            2    3
        //          /  \    \ 
        //        4     5     6
    cout << "\nTesting insertion of a node (6): \n";
    cout << root->value << endl;
    cout << root->left->value << endl;
    cout << root->right->value << endl;
    cout << root->left->left->value << endl;
    cout << root->left->right->value << endl;
    cout << root->right->left->value << endl;
    cout << "\nInorder: \n";
    DFT_inorder(root);
    cout << "\nPreorder: \n";
    DFT_preorder(root);
    cout << "\nPostorder: \n";
    DFT_postorder(root);

    //Testing deletion of a node
        //              1
        //             /  \ 
        //            6    3
        //          /  \    
        //        4     5   
    cout << "\nTesting deletion of a node: \n";  
    delete_node(root,2);
    cout << root->value << endl;
    cout << root->left->value << endl;
    cout << root->right->value << endl;
    cout << root->left->left->value << endl;
    cout << root->left->right->value << endl;
    cout << root->right->left->value << endl;

    //testing inorder (expecting 4, 2, 5, 1, 6, 3, 7,)
    //testing preorder (expecting 1, 2, 4, 5, 3, 6, 7,)
    //testing postorder (expecting 4, 5, 2, 6, 7, 3, 1,)
    //node *root = NULL;
    /*for(int i = 1; i <= 7; i++)
        insert(&root,i);
        //              1
        //             /  \ 
        //           2      3
        //         /  \    /  \ 
        //       4     5  6    7
    cout << "\nInorder: \n";
    DFT_inorder(root);
    cout << "\nPreorder: \n";
    DFT_preorder(root);
    cout << "\nPostorder: \n";
    DFT_postorder(root);*/
    



    return 0;
}