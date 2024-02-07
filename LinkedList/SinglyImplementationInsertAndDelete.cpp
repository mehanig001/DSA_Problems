//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

};

Node* insertAtHead(Node *head, int d){
    Node *temp = new Node(d);

    if(head == NULL)return temp;

    temp->next = head;
    return temp;
}

Node* insertAtEnd(Node* head , int d){
    Node *newnode = new Node(d);
    if(head == NULL)return newnode;

    Node *temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;

    return head;
}

Node* insertAtPos(Node* head , int d, int pos){
    //this code will insert element at end if given idx more than size
    if(pos == 1)return insertAtHead(head,d);

    int i = 0;//pointing head
    Node *newnode = new Node(d);
    if(head == NULL)return newnode;

    Node *temp = head;

    while(temp->next != NULL && i < pos-2){
        temp = temp->next;
        i++;
    }
    if(i!= pos-2)return head;
    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}

Node* deleteFromHead(Node* head){
    if(head == NULL)return NULL;
    
    Node *temp = head;
    head = head->next;
    delete(temp);
    return head;
}

Node* deleteLast(Node* head){
    if(head == NULL)return NULL;
    if(head->next == NULL){
        Node *temp = head;
        delete(temp);
        return NULL;
    }
    
    Node *temp = head;
    int i = 0;
    while(temp->next->next != NULL)temp = temp->next;
    
    Node* last = temp->next;
    temp->next = NULL;
    delete(last);
    return head;
}


Node* deleteFromPos(Node* head, int pos){
    if(head == NULL)return NULL;
    if(pos == 1)return deleteFromHead(head);

    Node *temp = head;
    int i = 0;
    while(temp->next->next != NULL && i < pos-2 ){
        temp = temp->next;
        i++;
    }
    if(i!=pos-2){//means pos>size no need to delete
        return head;
    }
    Node* last = temp->next;
    temp->next = temp->next->next;
    delete(last);
    return head;

}



void print(Node *head){
    Node *temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Node* head = NULL;
    head = insertAtHead(head,5);
    head = insertAtHead(head,4);
    head = insertAtHead(head,3);
    head = insertAtHead(head,2);
    head = insertAtHead(head,1);

    print(head);


    head = insertAtEnd(head,5);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,1);

    print(head);



    head = insertAtPos(head,10,11);

    print(head);


    head = deleteFromHead(head);
    head = deleteFromHead(head);
    head = deleteFromHead(head);

    print(head);
    
    head = deleteLast(head);
    head = deleteLast(head);
    
   

    print(head);


    head = deleteFromPos(head,2);

    
   

    print(head);


    return 0;
}