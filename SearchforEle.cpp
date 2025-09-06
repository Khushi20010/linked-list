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
    void insertatEnd(int val){
        Node* newnode = new Node(val);
        if(!head){
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next)temp = temp->next;
        temp->next = newnode;
    }
    bool SearchEle(int key){
         Node* temp = head;
    int position =1;
    while(temp){
        if(temp->data == key){
            cout<<"element  "<<key<<" found at "<<position<<endl;
            return true;
        }
        temp  =temp->next;
        position++;


    }
    cout<<"element  "<<key<<" not found at "<<position<<endl;
    return false;

    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"Null pointer\n";
    }
    int countnodes(){
        int count=0;
        Node* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
   

};
int main(){
    Linkedlist list;

list.insertatEnd(98);
list.insertatEnd(787);
list.insertatEnd(87);
list.insertatEnd(8787);
cout<<"element of linked list are:   ";
list.display();
list.SearchEle(98);
list.SearchEle(7877);
cout<<"number of nodes are:  "<<list.countnodes()<<endl;
return 0;

}
