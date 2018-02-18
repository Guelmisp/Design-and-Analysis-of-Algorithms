#include <iostream>
#include <cstddef>
#include <unordered_map>
#include <vector>

using namespace std;

//Count elements grater than a querie value.

class Node {
public:
    int data;
    int size = 0;
    Node *left;
    Node *right;
    
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

class Operations{
public:
    
    Node* insert(Node *node, int data){
        
        if (node == NULL ) return new Node(data);
        
        if (data < node -> data)
            node -> left = insert(node->left, data);
        else
            node -> right = insert(node->right, data);
        
        node -> size += 1;
        return node;
    }
    
    
    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << "Data: " << root -> data << " Size: " << root->size << endl;
            inorder(root->right);
        }
    }
    
    void search(Node *root, int data) {
    
        if (root->data == data) {
            cout << root->size << " "; return;
        }
        
        if (root->data < data) {
            if (root->right != NULL)
                return search(root->right, data);
            else
                cout << root->size-1 << " "; return;
        
        } else {
            if (root->left != NULL)
                return search(root->left, data);
            else
                cout << root->size-1 << " "; return;
        }
    }
    
};

int main() {
    Node* head=NULL;
    Operations btree;
    
    int numberofQueries, numberofElements;
    cin >> numberofQueries >> numberofElements;
    
    vector<int> queries (numberofQueries);
    
    for(int i = 0 ; i < numberofQueries; i++){
        cin >> queries[i];
    }
    
    for(int i = 0 ; i < numberofElements; i++){
        int value;
        cin >> value;
        head = btree.insert(head, value);
    }
    
    btree.inorder(head);
    
    cout << "Result: " << endl;
    
    for (int i = 0; i < numberofQueries; i++) {
        btree.search(head, queries[i]);
    }
    
}
