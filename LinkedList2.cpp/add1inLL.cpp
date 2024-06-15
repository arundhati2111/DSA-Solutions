#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            this->next=NULL;
        }
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
};

Node* reverseLL(Node* &head){
    Node* prev=NULL;
    Node* curr=head;
    

    while(curr != NULL){
        Node* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}

void addOne(Node* head){
    // reverse
    head=reverseLL(head);

    // add one
    int carry=1;
    Node* temp=head;
    while(temp->next != NULL){ //will stop on last node
        int totalSum=temp->data+carry;
        int digit=totalSum%10;
        carry=totalSum/10;

        temp->data=digit;
        temp=temp->next;
        if(carry==0){
            break;
        }
    }
    if(carry!=0){
    int totalSum=temp->data+carry;
    int digit=totalSum%10;
    carry=totalSum/10; // Update the existing carry variable

    temp->data=digit;

    if(carry!=0){
        Node* newNode=new Node(carry);
        temp->next=newNode;
    }
}

    // reverse
    head=reverseLL(head);


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

void printLL(Node* head){
    Node* temp=head;

    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,8);
    addOne(head);
    printLL(head);
}