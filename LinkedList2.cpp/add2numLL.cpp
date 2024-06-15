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

void addOne(Node* head1, Node* head2) {
    // Reverse both linked lists
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    Node* temp1 = head1;
    Node* temp2 = head2;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry != 0) {
        // If temp1 is not NULL, add its data to totalSum
        int totalSum = carry;
        if (temp1 != NULL) {
            totalSum += temp1->data;
            temp1 = temp1->next;
        }
        // If temp2 is not NULL, add its data to totalSum
        if (temp2 != NULL) {
            totalSum += temp2->data;
            temp2 = temp2->next;
        }

        // Calculate digit to be stored in current node
        int digit = totalSum % 10;
        carry = totalSum / 10;

        // Update data in temp1 node
        if (temp1 != NULL) {
            temp1->data = digit;
            if (temp1->next == NULL && carry != 0) {
                // If temp1 is the last node and there's a carry, create a new node
                Node* newNode = new Node(carry);
                temp1->next = newNode;
                carry = 0; // Reset carry as it's been absorbed
            }
        } else {
            // If temp1 is NULL but temp2 can still contribute digits
            Node* newNode = new Node(digit);
            temp1 = newNode;
            head1 = temp1; // Update head1 if it's the first node being created
        }
    }

    // Reverse both lists back to original order
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);
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
    Node* head1=NULL;
    Node* tail1=NULL;
    Node* head2=NULL;
    Node* tail2=NULL;
    insertAtTail(head1,tail1,1);
    insertAtTail(head1,tail1,3);
    insertAtTail(head1,tail1,4);
    insertAtTail(head2,tail2,2);
    insertAtTail(head2,tail2,3);
    // insertAtTail(head2,tail2,4);
    addOne(head1,head2);
    printLL(head1);
}