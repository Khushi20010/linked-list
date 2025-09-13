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
  Node* getintersection(Node* head1  , Node* head2){
    if(!head1||!head2) return nullptr;
    Node* p1 = head1;
    Node* p2 = head2;
    while(p1!=p2){
        p1 = (p1 == nullptr)?head2: p1->next;
        p2= (p2 == nullptr)?head1:p2->next;
    }
    return p1;
  }
};
int main(){
   Linkedlist list1 , list2;
   list1.insertAtEnd(10);
     list1.insertAtEnd(20);
       list1.insertAtEnd(30);
         list1.insertAtEnd(35);
         list2.insertAtEnd(40);
         list2.insertAtEnd(50);
         list2.insertAtEnd(60);
         Node* common = new Node(5);
         common->next = new Node(6);
         common->next->next  =  new Node(7);
         Node* temp = list1.head;
         while(temp->next)temp = temp->next;
         temp->next = common;
         temp = list2.head;
         while(temp->next)temp = temp->next;
         temp->next = common;
         cout<<"List 1:";
         list1.display();
              cout<<"List 2:";
         list2.display();
         Node* intersect = list1.getintersection(list1.head , list2.head);
         if(intersect){
            cout<<"Intersection happend at node with value:  "<<intersect->data<<endl;
         }
         else{
            cout<<"No intersection occurs"<<endl;
         }
         return 0;
            }