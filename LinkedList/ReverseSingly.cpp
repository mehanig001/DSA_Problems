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

Node *reverseItr(Node *head){
    Node *prev = NULL;
    Node *curr = head;

    while(curr != NULL){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node *reverseRec1(Node *head, Node*prev, Node* curr){
    if(curr == NULL)return prev;
    Node* nxt = curr->next;
    curr->next = prev;
    reverseRec1(head, curr, nxt);
}


Node *reverseRec2(Node *head){
    if(head == NULL || head->next == NULL)return head;

    Node*nxt = head->next;
    Node *temp = reverseRec2(head->next);

    nxt->next = head;
    head->next = NULL;
    return temp;
    
   
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
    // head = reverseItr(head);
    head = reverseRec2(head);
    // head = reverseRec1(head,NULL,head);
    print(head);

    return 0;
}