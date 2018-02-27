#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int key;
    int size;
    Node* right;
    Node* left;
    
    Node(int k) {
        size = 0;
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
        
        root->size = updateSize(root);
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
    
    int size(Node* root) {
        return root == NULL ? 0 : root->size;
    }
    
    int updateSize(Node* root) {
        return size(root->left) + size(root->right) + 1;
    };
    
    void depthFirst(Node *root) {
        if (root != NULL)
        {
            cout << "Key: " << root->key << " Size: " << root->size << endl;
            inorder(root->left);
            inorder(root->right);
        }
    }
    
    void breadthFirst(Node *root){
        if (root == NULL) return;
        queue<Node*> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            Node *p = queue.front();
            cout << p->key << " ";
            queue.pop();
            
            if (p->left != NULL)
                queue.push(p->left);
            if (p->right != NULL)
                queue.push(p->right);
        }
        cout << endl;
    }
    
    void inorder(Node *root) {
        if (root != NULL)
        {
            inorder(root->left);
            cout << "Key: " << root->key << " Size: " << root->size << endl;
            inorder(root->right);
        }
    }
};

int main() {
    Node* root = NULL;
    BST bst;
    vector<int> arr = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    
    for (int& arr_i : arr){
        root = bst.insert(root, arr_i);
    }
    
    cout << bst.find(root, 10) << endl;
    cout << bst.find(root, 44) << endl;
    
    bst.breadthFirst(root);
    bst.inorder(root);
    
    
    return 0;
}
