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

        ~Node(){
            cout<<"Destructor called for "<<this->data<<endl;
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

void deleteNode(Node* &head, Node* &tail, int position){
    // empty list
    if(head==NULL){
        cout<<"Linked list is empty"<<endl;
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

    int len=getLength(head);

    // delete from head i.e first node to be deleted
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    else if(position==len){
        // last node to be deleted i.e delete from tail
        Node* prev=head;
        while(prev->next != tail){
            prev=prev->next;
        }
        prev->next=NULL;
        delete tail;
        tail=prev;
    }

    else{
        // node to be deleted from between
        Node* prev=NULL;
        Node* curr=head;
        while(position != 1){
            prev=curr;
            curr=curr->next;
            position--;
        }
        prev->next=curr->next;
        // node isolate
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,50);
    printLL(head);
    insertAtPosition(head, tail, 40, 50);
    printLL(head);
    deleteNode(head,tail,1);
    printLL(head);
    deleteNode(head,tail,4);
    printLL(head);
    deleteNode(head,tail,2);
    printLL(head);
    return 0;


}