//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Node{
    public:

    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* insertAtHead(Node *head, int d){
    Node *temp = new Node(d);

    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    Node* ttemp = head; 
    while(ttemp->next != head)ttemp = ttemp->next;
    ttemp->next = temp;
    temp->next = head;

    return temp;
}

Node* insertAtEnd(Node *head, int d){
    Node *temp = new Node(d);

    if(head == NULL){
        temp->next = temp;
        return temp;
    }
    //JUGAAD FOR O(1)
    temp->next = head->next;
    head->next = temp;

    //swap values
    int x = head->data;
    head->data = temp->data;
    temp->data = x;
   
    return temp;
}


void print(Node*head){
    if(head ==  NULL){
        cout<<endl;
        return;
    }
    Node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    } 
    while(temp->next != head);

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
 

    head = insertAtEnd(head,6);
    head = insertAtEnd(head,7);

    print(head);






    return 0;
}