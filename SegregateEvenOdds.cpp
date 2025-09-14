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
void segregateEvenOdd(){
    if(!head||!head->next) return;
    Node* evenHead = nullptr;
     Node* oddHead = nullptr;
      Node* evenTail = nullptr;
       Node* oddTail = nullptr;
        Node* curr = head;
        while(curr){
            if(curr->data%2 == 0){//even
                if(!evenHead){
                    evenHead = curr;
                 evenTail = curr;
                }
                else{
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }

            }
            else{//odd
                if(!oddHead){
                    oddHead = curr;
                    oddTail = curr;
                }
                else{
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }

            }
            curr = curr->next;
        }
        if(!evenHead||!oddHead) return;
        evenTail->next = oddHead;
        oddTail->next = nullptr;
        head = evenHead;

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
    list.insertatEnd(7);
       list.insertatEnd(8);
          list.insertatEnd(9);
             list.insertatEnd(5);
                list.insertatEnd(90);
                   list.insertatEnd(89);
                   cout<<"Original List:  ";
                   list.display();
               
                   list.segregateEvenOdd();
                   cout<<"List after segregating  ";
                   list.display();
                   return 0;
}