#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){ //default ctor
            this->next=NULL;
            cout<<"Inside defuault ctor"<<endl;
        }

        Node(int data){
            this->data=data;
            this->next=NULL;
            cout<<"Inside parameterized ctor"<<endl;
        }
};

void printLL(Node* head){
    Node* temp=head;

    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
}

int main(){
    // Node n; STATIC ALLOCATION
    // DYNAMIC ALLOCATION
    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    Node* head=first;
    printLL(head);
    return 0;
}