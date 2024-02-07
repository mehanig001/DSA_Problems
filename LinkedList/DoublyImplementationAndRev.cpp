//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int d){
            data = d;
            prev = NULL;
            next = NULL;
        }
};

void insertAtHead(Node** head, int d){
    Node *newnode = new Node(d);
    
    if(*head == NULL)*head = newnode;
    else{
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    }
}

void insertBeforeElement(Node** head, int d, int key){
    if(*head == NULL)return;
    if((*head)->data == key){
        insertAtHead(head,d);
        return;
    }
    Node* temp = *head;
    Node* newnode = new Node(d);

    while(temp != NULL && temp->data != key){
        temp = temp->next;
    }
    if(temp->data != key)return;

    newnode->prev = temp->prev;
    temp->prev->next = newnode;
    newnode->next = temp;
    temp->prev = newnode;

}

void deleteFromFirst(Node **head){
    if(*head == NULL)return;
    
    Node* temp = *head;
    (*head) = (*head)->next; 
    delete(temp);


}

void deleteFromLast(Node **head){
    if(*head == NULL)return;
    if((*head)->next == NULL){
        deleteFromFirst(head);
    }
    Node* temp = *head;
    while(temp->next != NULL)temp = temp->next;

    temp->prev->next = NULL;
    delete(temp);


}
void rev(Node **head){
    Node* p = NULL;
    Node* c = *head;

    while(c != NULL){
        Node* n = c->next;
        c->next = p;
        c->prev = n;

        p = c;
        c = n;


        *head = p;
    }
}

void print(Node ** head){
    Node* temp = *head;
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


    insertAtHead(&head,5);
    insertAtHead(&head,4);
    insertAtHead(&head,3);
    insertAtHead(&head,2);
    insertAtHead(&head,1);

    insertBeforeElement(&head,10,1); //O(1) in doubly if we know ptr to it
    print(&head);

    deleteFromFirst(&head);
    print(&head);

    deleteFromLast(&head);
    print(&head);

    rev(&head);
    print(&head);

    


    return 0;
}