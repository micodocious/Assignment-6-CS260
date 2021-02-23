/*
Assignment 6 (Binary search tree)(two week assignment)
Mico Santiago

This is a binary search tree or BST, one of the many node based binary tree data structure. Its properties as follows in the lecture example. Left side < root, right side > root, 
only two children per node and no duplicate nodes. 

Why is this particular data struture useful? Becuase it is fast way to find something. IF we had a random marble in a pot of marbles all labeled to 1-100 we can use this data structure
to cut it in half until we find it. 


*/

#include <iostream>
using namespace std;
#include "BST.cpp"

using std::cout;
using std::endl;

//
int main(int argc, char **argv) {
    struct node *root = NULL;
    root = insert(root,50);
    root = insert(root,60);
    root = insert(root,30);
    root = insert(root,90);
    root = insert(root,20);
    root = insert(root,40);
    root = insert(root,55);
        //              50
        //             /  \ 
        //           30    60
        //          / \   /  \ 
        //        20  40 55   90
    cout << "\nTesting insertion function: \n";
    cout << root->value << endl;
    cout << root->left->value << endl;
    cout << root->right->value << endl;
    cout << root->left->left->value << endl;
    cout << root->left->right->value << endl;
    cout << root->right->left->value << endl;
    cout << root->right->right->value << endl;
    cout << "\n---------------------------- \n";
    cout << "\nInorder traversal of tree \n";
    BST_inorder(root);

    cout << "\nPreorder traversal of tree \n";
    BST_preorder(root);

    cout << "\nPost traversal of tree \n";
    BST_postorder(root);
    cout << "\n---------------------------- \n";

        //Testing deletion function
        //delete 20
        //              50
        //             /  \ 
        //           30    60
        //            \   /  \ 
        //            40 55   90
    cout << "\nDelete 20\n";
    root = delete_node(root, 20);
    cout << "Inorder traversal of tree \n";
    BST_inorder(root);
        //delete 30
        //              50
        //             /  \ 
        //           40    60
        //                /  \ 
        //               55   90
 
    cout << "\nDelete 30\n";
    root = delete_node(root, 30);
    cout << "Inorder traversal of tree \n";
    BST_inorder(root);
        //              55
        //             /  \ 
        //           40    70
        //                   \ 
        //                    90
    cout << "\nDelete 50\n";
    root = delete_node(root, 50);
    
 
    return 0;
}