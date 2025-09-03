#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
data = val;
next = nullptr;
    }
    

};
class SinglyLinkedList{
    private:
    Node* head;
    public:
    SinglyLinkedList(){
 head = nullptr;
    }
    //insert at  start
    void insertatBeginning(int val){
        Node* newNode = new Node(val);
        newNode -> next = head;
        head = newNode;
    }
    //insert at end
    void insertatEnd(int val){
        Node*  newNode = new Node(val);
        if(!head){
            head = newNode;
            return ;
        }
        Node* temp = head;
        while(temp -> next) temp = temp->next;
        temp-> next = newNode;
    }
    //insert at specific position
    void insertatSpecificposition(int pos , int val){
        if(pos == 1);
        insertatBeginning(val);
        return;
        Node* newNode = new Node(val);
            Node* temp = head;
            for(int i=1;temp&&i<pos-1; i++)
                temp =temp->next;
                if(!temp){
 cout<<"position out of range\n";
                delete newNode;
                return ;
                }
                  newNode->next = temp->next;
            temp->next = newNode;
              }
              
               
            
          

        
  
    
   

};