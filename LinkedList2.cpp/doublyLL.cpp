#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        // ctor
        Node(){
            this->prev=NULL;
            this->next=NULL;
        }

        Node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
};

void print(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->data<<"-> ";
        temp=temp->next;
    }cout<<endl;
}

int getLength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail,int data){
    // LL is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }

    // LL is not empty
    else{
        Node* newNode=new Node(data);
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }

}

void insertAtTail(Node* &head,Node* &tail,int data){
    // LL is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    // LL is not empty
    else{
        Node* newNode=new Node(data);
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    // LL is empty
    if(head==NULL){
        Node* newNode=new Node(data);
        head=newNode;
        tail=newNode;
    }
    // LL is not empty
    else{
        int len=getLength(head);
        if(position==1){
            insertAtHead(head,tail,data);
            return;
        }
        if(position==len+1){
            insertAtTail(head,tail,data);
            return;
        }
        else{
            // insert in between
            // create new node
            Node* newNode=new Node(data);
            // prev and curr pointers
            Node* prevNode=NULL;
            Node* currNode=head;
            while(position!=1){
                prevNode=currNode;
                currNode=currNode->next;
                position--;
            }
            prevNode->next=newNode;
            newNode->prev=prevNode;
            newNode->next=currNode;
            currNode->prev=newNode;

        }
    }
}

void deleteNode(Node* &head, Node* &tail,int position){
    int len=getLength(head);
    if(head==NULL){
        cout<<"Linked List is empty, cannot insert!"<<endl;
        return;
    }
    if(head==tail){
        // single element
        Node* temp=head;
        delete temp;
        head=NULL;
        tail=NULL;
        return;
    }
    if(position==1){
        // delete from head
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
    }    
    else if(position==len){
        // delete from tail
        Node* prevNode=tail->prev;
        prevNode->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail=prevNode; 
    }
    else{
        Node* prevNode=NULL;
        Node* currNode=head;
        while(position!=1){
            prevNode=currNode;
            currNode=currNode->next;
            position--;
        }
        Node* nextNode=currNode->next;

        prevNode->next=nextNode;
        currNode->prev=NULL;
        currNode->next=NULL;
        nextNode->prev=prevNode;

        delete currNode;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(head,tail,40);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,10);
    print(head);
    insertAtTail(head,tail,50);
    print(head);
    insertAtPosition(head,tail,100,1);
    print(head);
    insertAtPosition(head,tail,200,6);
    print(head);
    insertAtPosition(head,tail,300,8);
    print(head);
    cout<<endl;
    cout<<"Deleting node"<<endl;
    deleteNode(head,tail,1);
    print(head);
    deleteNode(head,tail,7);
    print(head);
    deleteNode(head,tail,3);
    print(head);
}