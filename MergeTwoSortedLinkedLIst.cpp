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
Node* mergeIterative(Node* l1,  Node*l2){
    Node dummy(-1);
    Node* tail = &dummy;
    while(l1&&l2){
        if(l1->data<=l2->data){
            tail->next =l1;
            l1 = l1->next; 
        }
        else{
             tail->next =l2;
            l2 = l1->next;

        }
    }
    tail = tail->next;
    if(l1)tail->next  = l1;
    if(l2) tail->next = l2;
}
        //Recursive method
      Node* meregRecursive(Node*l1 , Node*l2){
        if(!l1) return l2;
          if(!l2) return l1;
          if(l1->data<=l2->data){
            l1->next = meregRecursive(l1->next , l2);
          }
          else{
            l2->next = meregRecursive(l1 , l2->next);
          }

      }
 };
 int main(){
    Linkedlist list1 , list2;
    //First list
    list1.insertAtEnd(89);
       list1.insertAtEnd(90);
          list1.insertAtEnd(91);
          //Second list
          list2.insertAtEnd(60);
              list2.insertAtEnd(61);
                  list2.insertAtEnd(62);
                  cout<<"The list one  are  ";
                  list1.display();
                    cout<<"The list two  are  ";
                    list2.display();
                    //merge iterative
                  cout<<"Merge list by iterative method";
                  Node* merged1 = list1.mergeIterative(list1.head , list2.head);
                    Node* temp = merged1;
                    while(temp){
                        cout<<temp->data<<"->";
                        temp = temp->next;
                    }
                    cout<<"Null pointer"<<endl;
                  
                    //Another list for recursive merge

                    Linkedlist list3  , list4;
                    //list 3
                    list3.insertAtEnd(10);
                    list3.insertAtEnd(11);
                    list3.insertAtEnd(12);
                    //list4
                    list4.insertAtEnd(20);
                     list4.insertAtEnd(21);
                      list4.insertAtEnd(22);
                      cout<<"The third list are:  ";
                      list3.display();
                   cout<<"The Fourth list are:  ";
                      list4.display();
                      //merge recursively
                  cout<<"Merge list recursively";
                  Node* merged2 = list3.meregRecursive(list3.head , list4.head);
              temp = merged2;
                  while(temp){
                    cout<<temp->data<<"->";
                    temp  = temp->next;
                  }
                  cout<<"Null pointer"<<endl;
                      return 0;


 }