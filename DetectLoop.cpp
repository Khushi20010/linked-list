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
    public:
    Linkedlist(){
        head = nullptr;
    }

    void insertAtEnd(int val){
        Node* newnode = new Node(val);
        if(!head){
            head = newnode;
            return;

        }
        Node* temp  =head;
        while(temp->next) temp =  temp->next;
        temp->next = newnode;
        

    }
    void createLoop(int pos){
       if(pos == 0) return;
       Node* loopnode = head;
       for(int i=1;i< pos && loopnode;i++){
        loopnode = loopnode->next;
       }
       Node* temp  =head;
       while(temp->next)temp = temp->next;
       temp->next = loopnode;
    }

    bool  detectLoop(){
        Node*slow = head;
        Node*fast = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
    void display(){
        Node* temp  =head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"null pointer";
    }
    };
    int main(){
        Linkedlist list;
        list.insertAtEnd(8);
           list.insertAtEnd(8767);
              list.insertAtEnd(845);
                 list.insertAtEnd(87);
                 cout<<"Original list are:  \n";
                 list.display();
                 list.createLoop(3);
                 if(list.detectLoop()){
                    cout<<"\nLoop is detected:\n";
                 }
                 else{
                    cout<<"\nNo loop is detected\n";
                 }
                 return 0;
                
    }
