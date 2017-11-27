#include <iostream>
#include <cstddef>
using namespace std;  
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public: 
      Node* insertFront(Node *head,int data)
      {
          Node * newNode = new Node(data);
          newNode->next = head;
          head = newNode;

          return head;

      } 
      Node* insertBack(Node *head,int data)
      {
          Node* newNode = new Node(data);
          
          if (head == NULL)
              return newNode;
          
          if (head -> next == NULL) {
              head -> next = newNode;
          } else {
              insert(head -> next, data);
          }
          return head;

      }
      Node* deleteFromHead(Node *head) {
        Node* nextNode;

        if (head) {
          nextNode = head->next;
          delete(head);
          return nextNode;
        }

        return head;
      }
      
      void deleteList( Node *head ) {
        Node * nextNode;
        while(head) {
          nextNode = head->next;
          delete(head);
          head = nextNode;
        }
      }

      void display(Node *head)
      {
          Node *start=head;
          while(start)
          {
              cout<<start->data<<" ";
              start=start->next;
          }
      }

      void removeDuplicates1( Node * head ) {
        if ( head == nullptr || ( head && (head->next == nullptr) )) {
          return ;
        }
        std::unordered_map<int, int> node_map;
        Node * prev = head;
        Node * curr = head->next;
        node_map[head->data] = 1;
        while( curr != nullptr ) {
          while (curr && node_map.find(curr->data) != node_map.end()) {
            curr = curr->next;
          }
          prev->next = curr;
          prev = curr;
          if (curr) {
            node_map[curr->data] = 1;
            curr = curr->next;
          }
        }
      }

      void reverse( Node * & head ) {
        if ( head == nullptr  || (head && (head->next == nullptr))){
          return;
        }
        Node * newHead = nullptr;
        Node * nextNode = nullptr;
        while ( head ) {
          nextNode = head->next;
          head->next = newHead;
          newHead = head;
          head = nextNode;
        }
        head = newHead;
      }
};
int main()
{
  Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    } 
  mylist.display(head);
    
}
