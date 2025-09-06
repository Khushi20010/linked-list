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
    void printReverseRec(Node* node){
        if(!node) return;
        printReverseRec(node->next);
        cout<<node->data<<" ";
    }
    public:
    Linkedlist(){
            head = nullptr;

    }
    void insertAtBegin(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void findnthEle(int n){
        if(n<=0){
            cout<<"invalid position\n";
            return;
        }
        Node* first = head;
        Node* second = head;
        for(int i=0;i<n;i++){
            if(!first){
                cout<<"position out of range"<<endl;
                return;
            }
            first = first->next;
        }
        while(first){
            first = first->next;
            second = second->next;

        }
        cout<<"the  "<<n<<"th node from the end is:  "<<second->data<<endl;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp  =temp->next;
        }
        cout<<"Null pointer\n";
    }
    void printReverse(){
        printReverseRec(head);
        cout<<endl;
    }



} ;
int main(){
    Linkedlist list;
    list.insertAtBegin(787);
    list.insertAtBegin(787);
    list.insertAtBegin(6867);
    cout<<"Original Linked list are:  ";
    list.display();
    list.findnthEle(2);
    list.findnthEle(3);
    cout<<"reverse list are: ";
    list.printReverse();
    return 0;
}