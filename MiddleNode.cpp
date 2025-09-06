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
   head  = nullptr;
    }
 

    void insertAtBegin(int val){
Node*  newnode = new Node(val);
newnode-> next = head;
head = newnode;

    }
    void inserAtEnd(int val){
         Node* newnode = new Node(val);
        if(!head){
            head = newnode;
            return ;
        }
       
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newnode;
    }

    void inserAtSpecificPssition(int pos , int val){
        if(pos == 1){
            insertAtBegin(val);
            return;
        }
        Node* newnode = new Node(val);
        Node* temp = head;
        for(int i=1;temp&&i<pos-1; i++ ){
            temp = temp->next;

        }
        if(!temp){
            cout<<"position out of range\n";
            delete newnode;
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    int countNodes(){
        int count = 0;
        Node*  temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
   void display(){
    Node*  temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"Null pointer\n";
   }
   void printReverse(){
    printReverseRec(head);
    cout<<endl;
   }

   void middleNode(){
    if(!head){
        cout<<"list is empty\n";
        return;
    }
    Node* slow = head;
    Node* fast = head;
    while(head&&head->next){
slow = slow->next;
fast = fast->next->next;
cout<<"Middle node found at"<<slow->data<<endl;
    }
   }
};
int main(){
    Linkedlist list;
    list.inserAtEnd(9789);
    list.inserAtSpecificPssition(2,9898);
    list.insertAtBegin(87);
    list.insertAtBegin(999);
    cout<<"original list are:";
    list.display();
    cout<<"Number of nodes are:"<<list.countNodes()<<endl;
    cout<<"Reverse list are:";
    list.printReverse();
    list.middleNode();
    return 0;
}