#include <iostream>
#include "node.h"
#include <queue>

using namespace std;

using std::cout;
using std::endl;


node *create_node(int value){
    node *my_node = new node();
    my_node->value = value;
    my_node->left = NULL;
    my_node->right = NULL;
    return my_node;
}

// Level Order Traversal or Breath First Traversal
node *search(node *root, int value){
    if(root == NULL)
        return NULL;
    queue < node* > q;
    node *out = NULL;
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        if(temp->value == value) {out = temp; cout << "HIT" << endl;}
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);

    }
    return out;
}
// Insertion by finding the first vacant node in a BFT (LOT) fashion
void insert(node **root, int value){
    if(*root == NULL){
        cout << "THE ROOT IS NULL" << endl;
        *root = create_node(value);
        return;
    }
    //assuming the tree isn't empty
    node *node_to_insert = create_node(value);
    queue<node*> q;
    q.push(*root);

    while(! q.empty()){
        node *temp = q.front();
        q.pop();
        //check left
        if(temp->left == NULL){
            temp->left = node_to_insert;
            return;
        }
        else{
            q.push(temp->left);
        }
        //check right
        if(temp->right == NULL){
            temp->right = node_to_insert;
            return;
        }
        else{
            q.push(temp->right);
        }
    }
}
//
void set_furthest_right_to_null(node *root, node *furthest_right){
    queue<node*> q;
    q.push(root);
    node *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left != NULL){
            if(temp->left == furthest_right){
                cout << "FOUND " <<endl;
                temp->left = NULL;
                return;
            }
            else{
                q.push(temp->left);
            }
        }
        if(temp->right != NULL){
            if(temp->right == furthest_right){
                cout << "FOUND " <<endl;
                temp->right = NULL;
                return;
            }
            else{
                q.push(temp->right);
            }
        }
    }
}
//
void delete_node(node *root, int value){
    node *node_to_delete = search(root,value);
    if(node_to_delete != NULL){
        queue<node*> q;
        q.push(root);
        node *temp;
        while(!q.empty()){
            temp = q.front();
            q.pop();

            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
        //We have to perform the 3 steps stated earlier
        int value_at_deepest_right = temp->value;
        // Look for a node in the tree that point to the furtest right
        set_furthest_right_to_null(root,temp);
        // delete the node_to_delete
        node_to_delete->value = value_at_deepest_right;
    }
    
}
//inorder
void DFT_inorder(node *root){
    if(root == NULL)
        return;

    DFT_inorder(root->left);
    cout << root->value << ", ";
    DFT_inorder(root->right);
}
//preorder
void DFT_preorder(node *root){
    if(root == NULL)
        return;

    cout << root->value << ", ";
    DFT_preorder(root->left);
    DFT_preorder(root->right);
}
//postorder
void DFT_postorder(node *root){
    if(root == NULL)
        return;

    DFT_postorder(root->left);
    DFT_postorder(root->right);
    cout << root->value << ", ";
}




