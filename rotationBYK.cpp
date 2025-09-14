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
    void insertAtEnd(int val){
        Node* newnode = new Node(val);
        if(!head){
            head = newnode;
            return;
        }
        Node* temp = head;
        while(temp->next)temp = temp->next;
        temp->next  = newnode;
    }
    void display(){
        Node* temp = head;
        while(temp){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"Null pointer\n";
    }
       Node* rotatebyK(Node* head , int k){
        if(!head||!head->next||k==0) return nullptr;
        Node* temp = head;
        int length = 1;
        while(temp->next){
            temp = temp->next;
               length++;

        }
        temp->next = head;
        k = k%length;
        int stepstonewhead = length-k;
        Node* newTail  =head;
        for(int i=1;i<stepstonewhead;i++){
            newTail = newTail->next;

        }
        Node* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
     

       }
};
int main(){
    Linkedlist list;
    list.insertAtEnd(3);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);
    list.insertAtEnd(7);
    cout<<"original List are: ";
    list.display();
   int k = 4;
   list.head = list.rotatebyK(list.head , k);
   cout<<"Rotated List by"<<k<<":";
   list.display();
   return 0;
}