#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        // default constructor
        // Node(){
        //     this->data=NULL;
        // }
        // Parameterised constructor
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
}

int getLen(Node* &head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,int data,Node* &tail){
    // if list is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    // list non empty
    else{
        Node* newNode=new Node(data);
        newNode->next=head;
        head=newNode;
    }
}

void insertAtTail(Node* &head,int data,Node* &tail){
    // if list is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
}

void insertAtPosition(Node* &head,int data,Node* &tail,int pos){
    if(pos==1){
        insertAtHead(head,data,tail);
    }
    int len=getLen(head);
    if(pos==len+1){
        insertAtTail(head,data,tail);
    }
    else{
        Node* newNode=new Node(data);
        Node* prev=NULL;
        Node* curr=head;
        while(pos!=1){
            prev=curr;
            curr=curr->next;
            pos--;
        }
        prev->next=newNode;
        newNode->next=curr;
    }
}

int main(){
    // // static creation 
    // Node n1(5);

    // // Dynamic creation
    // Node* first=new Node(10);
    // Node* second=new Node(20);
    // Node* third=new Node(30);
    // Node* fourth=new Node(40);
    // Node* fifth=new Node(50);

    // // link the nodes to each other
    // first->next=second;
    // second->next=third;
    // third->next=fourth;
    // fourth->next=fifth;

    // Node* head=first;
    // Node* tai=fifth;

    // print(head);
    // cout<<endl;
    // int length=getLen(head);
    // cout<<"Lenght of list is "<<length<<endl;

    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,10,tail);
    insertAtHead(head,20,tail);
    insertAtHead(head,30,tail);
    insertAtTail(head,40,tail);
    insertAtPosition(head,50,tail,3);
    print(head);

}