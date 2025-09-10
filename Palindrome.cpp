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
class Linkedlist{
    private:
    Node* head;
    Node* reverseList(Node* head ){
        Node* prev = nullptr;
           Node* curr = head;
              Node* Next = nullptr;
              while(curr){
                Next = curr->next;
                curr->next = prev;
                prev=  curr;
                curr = Next;


              }
              return prev;
    }
    public:
    Linkedlist(){
        head = nullptr;
    }
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            return ;
        }
        Node* temp = head;
        while(temp->next)temp = temp->next;
        temp->next = newNode;

    }

    bool checkPlindrome(){
        if(!head||!head->next) return true;
        Node* slow = head;
        Node* fast = head;
        while(fast &&fast->next){
            slow = slow->next;
            fast = fast->next->next;

        }
    
        Node* secondHalf =reverseList(slow);

        Node* firstHalf = head;
        while(secondHalf){
            if(firstHalf->data!= secondHalf->data){
  return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
          
        }
        return true;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"nullptr\n";
        
    }

};
int main(){
    Linkedlist list;
    list.insertAtEnd(6767);
    list.insertAtEnd(565);
      list.insertAtEnd(56675);
        list.insertAtEnd(5665);
          list.insertAtEnd(55465);
          list.display();
          if(list.checkPlindrome()){
            cout<<"this is a palindome"<<endl;
           
          }
           else{
                cout<<"this is not a palindrome"<<endl;
            }
            return 0;

}