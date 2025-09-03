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

    void insertatBegin(int val){
        Node* newnode  = new Node(val);
        newnode->next = head;
        head  =  newnode;
    }
    void insertatEnd(int val){
           Node* newnode  =new Node(val);
        if(!head){
            head  = newnode;
            return ;
        }
     
        Node* temp = head;
        while(temp->next)temp =temp->next;
        temp->next = newnode;
    }
    void insertatspecificposition(int pos  , int val){
        if(pos == 1){
            insertatBegin(val);
            return;
        }
        Node* newnode  = new Node(val);
        Node* temp =head;
     
       for(int i=1;temp&& i<pos-1; i++){
temp  =temp->next;
       }
       if(!temp){
        cout<<"position out of range\n";
        delete newnode;
        return;
       }
       newnode->next = temp->next;
       temp->next = newnode;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;

        }
        cout<<"null\n";
    }
};
int main(){
    Linkedlist list;
    list.insertatBegin(89);
    list.insertatEnd(787778);
    list.insertatEnd(978);
    list.insertatBegin(9897);
    list.insertatspecificposition(2 , 89);
    list.insertatspecificposition(3 , 89898);
    cout<<"linked list are:  ";
    list.display();
    return  0;
}