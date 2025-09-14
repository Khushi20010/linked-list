#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    int data;
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
            Node* newnode = new Node(val);
            if(!head){
                head  = newnode;
                return;
            }
            Node* temp = head;
            while(temp->next)temp = temp->next;
           temp->next = newnode; 
        }
        void removeduplicates(){
            Node* curr = head;
            while(curr&&curr->next){
                if(curr->data  ==  curr->next->data){
                    Node* dupl = curr->next;
                    curr->next = curr->next->next;
                    delete dupl;
                }
                else{
                    curr = curr->next;

                }
            }
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
    Linkedlist sortedList;
    sortedList.insertatEnd(1);
     sortedList.insertatEnd(2);
      sortedList.insertatEnd(2);
       sortedList.insertatEnd(3);
        sortedList.insertatEnd(4);
         sortedList.insertatEnd(4);
         cout<<"Original List are:  ";
         sortedList.display();
         sortedList.removeduplicates();
         cout<<"Final list after removing duplicates are:  ";
         sortedList.display();
         return 0;
}