#include <iostream>
#include "node.h"

using std::cout;
using std::endl;

//create a structure of a node
struct node *create_node(int value){
    node *temp = new node();
    temp->value = value;
    temp->left = temp->right = NULL;
    return temp;

}
//insert function with given value using BST
struct node* insert(struct node* node, int value){
    //if the tree is empty, return a new node
    if(node == NULL)
        return create_node(value);
    //if the tree isn't empty repeatedly go down the tree
    if (value < node->value)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
 
    //return the (unchanged) node pointer
    return node;
}
//with a non empty binary search tree, return the node with the lowest value. 
struct node* min_value(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
//deletion function, when given a BST and a value, deletes the value and returns a new root
struct node* delete_node(struct node* root, int value)
{
    // base case
    if (root == NULL)
        return root;
 
    // If the value to be deleted is smaller than the root's value, then it goes left
    if (value < root->value)
        root->left = delete_node(root->left, value);
 
    // If the value to be deleted is greater than the root's value, then it goes right
    else if (value > root->value)
        root->right = delete_node(root->right, value);
 
    // if value is same as root's value, delete value
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest in the right subtree)
        struct node* temp = min_value(root->right);
 
        // Copy the inorder successor's content to this node
        root->value = temp->value;
 
        // Delete the inorder successor
        root->right = delete_node(root->right, temp->value);
    }
    return root;
}
//inorder traversal of BST
void BST_inorder(struct node* root)
{
    if (root != NULL) {
        BST_inorder(root->left);
        cout << root->value<< ", ";;
        BST_inorder(root->right);
    }
}
//preorder
void BST_preorder(struct node* root)
{
    if (root != NULL) {
        cout << root->value<< ", ";;
        BST_inorder(root->left);
        BST_inorder(root->right);
    }
}
//postorder
void BST_postorder(struct node* root)
{
    if (root != NULL) {
        BST_inorder(root->left);
        BST_inorder(root->right);
        cout << root->value<< ", ";;
    }
}
