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
    int countNodes(){
        int count =0;
        Node* temp  =head;
        while(temp){
            count++;
            temp  =temp->next;

        }
        return count;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"null pointer";
    }
//reversing iteratively method
    void reverseList(){
        Node* curr = head;
        Node* prev = nullptr;
        Node* NextNode = nullptr;
        while(curr){
            NextNode = curr->next;
            
            curr->next = prev;
            prev = curr;
            curr = NextNode;
        }
        head = prev;
    }
};
int main(){
    Linkedlist list;
    list.insertAtEnd(9);
     list.insertAtEnd(900);
      list.insertAtEnd(9787);
       list.insertAtEnd(9787);
        list.insertAtEnd(98676);
        cout<<"Original List are\n";
        list.display();
        cout<<"Reverse list are:\n " ;
        list.reverseList();
        list.display();
        cout<<"Number of nodes are\n  "<<list.countNodes()<<endl;
        return 0;

}