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

    bool serachEle(int key){
        int pos  = 1;
        Node* temp  =head;
        while(temp){
            if(temp->data == key){
                cout<<"Element "<<key<<"found at this"<<pos<<endl;
                return true;
            }
            temp = temp->next;
            pos++;
        }
        cout<<"Element "<<key<<"not found at"<<pos<<endl;
    }
    void createLoop(int pos){
       if(pos == 0) return;
       Node* loopnode = head;
       for(int i=0;i< pos && loopnode;i++){
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

    void deleteLoop(){
        Node* slow = head;
        Node* fast = head;
        while(fast&&fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        if(slow!=fast) return;
        slow = head;
        if(slow == fast){
            while(fast->next!=slow) fast = fast->next;
             }
            else{
                while(slow->next!=fast->next){
                    slow  =slow->next;
                    fast = fast->next;
                }
            }
            fast->next = nullptr;
       
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
                 list.serachEle(56565);
                 list.display();
                 list.createLoop(3);
                 if(list.detectLoop()){
                    cout<<"\nLoop is detected:\n";
                    list.deleteLoop();
                    cout<<"loop is removed";
                 }
                 else{
                    cout<<"No loop is detected\n";
                 }
                 return 0;
                
    }
