#include <iostream>
#include <cstddef>
#include <unordered_map>
#include <vector>

using namespace std;

//Count elements grater than a querie value.

class Node {
public:
    int data;
    int smallerThan = 0;
    Node *left;
    Node *right;
    
    Node(int d, int s){
        data=d;
        smallerThan = s;
        left=NULL;
        right=NULL;
    }
};

class Tree{
public:
    
    Node* buildTree(vector<int> arr){
        
        sort(arr.begin(), arr.end());
        
        return buildTree(arr, 0, arr.size()-1);
        
    }
    
    Node* buildTree(vector<int> arr, int start, int end){
        if (end < start)
            return NULL;
        
        int midPoint = (start + end)/2;
        Node *root = new Node(arr[midPoint], midPoint);
        
        root->left = buildTree(arr, start, midPoint - 1);
        root->right = buildTree(arr, midPoint + 1, end);
        
        return root;
        
    }
    
    int search(Node *root, int data) {
        
        //if (root == NULL || root->data == data)
        //    return root;
        
        //return (data < root->data ) ? search(root->left, data) : search(root->right, data);
        
        if (root->data == data)
            return root->smallerThan;
        
        if (data < root->data )
            return (root->left != NULL) ? search(root->left, data) : root->smallerThan+1;
        else
            return (root->right != NULL) ? search(root->right, data) : root->smallerThan+1;
    }
    
    void inorder(Node *root)
    {
        if (root != NULL)
        {
            inorder(root->left);
            cout << "Data: " << root -> data << " SL: " << root->smallerThan << endl;
            inorder(root->right);
        }
    }
    
};

int main() {
    Node* head=NULL;
    Tree tree;
    
    int numberofQueries, numberofElements;
    cin >> numberofQueries >> numberofElements;
    
    vector<int> queries (numberofQueries);
    vector<int> arr (numberofElements);
    
    for(int i = 0 ; i < numberofQueries; i++)
        cin >> queries[i];
    
    for(int i = 0 ; i < numberofElements; i++)
        cin >> arr[i];
    
    head = tree.buildTree(arr);
    
    
    tree.inorder(head);
    
    cout << "Result: " << endl;
    
    for (int i = 0; i < numberofQueries; i++)
        cout << tree.search(head, queries[i]) << " ";
    
    
    
}
