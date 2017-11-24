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
