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
    public:
       Node* head;
    Linkedlist(){
        head = nullptr;
    }
void insertatEnd(int val){
           Node* newnode  =new Node(val);
        if(!head){
            head  = newnode;
            return ;
        }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newnode;
}
Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* curr =head;
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void deleteMax(){
      if(!head||!head->next) return;
    head = reverse(head);
  
    Node* curr = head;
    Node* maxNode = head;
    while(curr&&curr->next){
        if(curr->next->data<maxNode->data){
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;


        }
        else{
            curr = curr->next;
            maxNode = curr;
        }
    }
    head = reverse(head);
}
void display(){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"Null pointer"<<endl;
}
};
int main(){
    Linkedlist list;
    list.insertatEnd(12);
        list.insertatEnd(15);
            list.insertatEnd(10);
                list.insertatEnd(11);
                    list.insertatEnd(5);
                        list.insertatEnd(6);
                           list.insertatEnd(3);
                        cout<<"Original List are:  ";
                        list.display();
                        list.deleteMax();
                        cout<<"after deleting nodes having greater value on the right:  ";
                        list.display();
                        return 0;
}