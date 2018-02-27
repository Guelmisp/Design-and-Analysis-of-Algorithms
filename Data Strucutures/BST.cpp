#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int key;
    Node* right;
    Node* left;
    
    Node(int k) {
        key = k;
        right = NULL;
        left =  NULL;
    }
};

class BST {
public:
    
    Node* insert(Node* root, int key) {
        
        if (root == NULL)
            return new Node(key);
        
        if (key < root->key) {
            root->left = insert(root->left, key);
        } else {
            root->right = insert(root->right, key);
        }
        
        return root;
        
    }
    
    int find(Node* root, int key) {
        if (root == NULL)
            return -1;
        else if (root->key == key)
            return key;
        
        return key < root->key ?  find(root->left, key) :  find(root->right, key);
    }
    
    Node* getMin(Node* root) {
        return root->left == NULL ? root : getMin(root->left);
    }
    
    Node* getMax(Node* root) {
        return root->right == NULL ? root : getMax(root->right);
    }
    
    void inorder(Node *root) {
        if (root != NULL)
        {
            inorder(root->left);
            cout << "Key: " << root -> key << endl;
            inorder(root->right);
        }
    }
};

int main() {
    Node* root = NULL;
    BST bst;
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    
    for (int& i : arr){
        root = bst.insert(root, i);
    }
    
    cout << bst.find(root, 10) << endl;
    cout << bst.find(root, 44) << endl;
    
    bst.inorder(root);
    
    
    return 0;
}
