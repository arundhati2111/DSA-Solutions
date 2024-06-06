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
    cout<<endl;
}

int getLength(Node *head){
    Node* temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}

void insertAtHead(Node* &head,Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
            
        }
        
}

void insertAtTail(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}

void createTail(Node* &head,Node* &tail){
    Node* temp=head;
    while(temp->next!=NULL){

        temp=temp->next;
    }
    tail=temp;
}


void insertAtPosition(Node* &head, Node* &tail,int data, int position){
    // if(position<1){
    //     cout<<"Cannot insert, Please enter a valid position."<<endl;
    //     return;
    // }
    int length=getLength(head);
    // if(position>length){
    //     cout<<"Cannot insert, Please enter a valid position."<<endl;
    //     return;
    // }

    if(position<=1){
        insertAtHead(head,tail,data);
    }

    else if(position > length){
        insertAtTail(head,tail,data);
    }

    else{
        // insert in between linked list 
        // step1: create a node
        Node *newNode=new Node(data);
        // step 2: traverse prev and curr to position
        Node *prev=NULL;
        Node *curr=head;
        while(position != 1){
            prev=curr;
            curr=curr->next;
            position--;
        }
        // attach prev to new node
        prev->next=newNode;
        // attach new node to current
        newNode->next=curr;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    // insertAtHead(head,tail,60);
    // printLL(head);
    // insertAtTail(head,tail,500);
    // printLL(head);
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,50);
    printLL(head);
    // insertAtPosition(head, tail, 40, 0); Cannot insert, Please enter a valid position.
    // insertAtPosition(head, tail, 40, 6);  Cannot insert, Please enter a valid position.
    insertAtPosition(head, tail, 40, 50);
    printLL(head);
    return 0;


}