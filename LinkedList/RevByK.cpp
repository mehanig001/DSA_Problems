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



Node *reverseByK(Node *head, int k){

    if(head == NULL || head->next == NULL)return head;
    Node *prev = NULL;
    Node *curr = head;
 

    int i = 0;
    while(curr != NULL && i < k){
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        i++;
    }

    

    Node *newprev = reverseByK(curr,k);

    head->next = newprev;
    head = curr;


    return prev;
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
    head = insertAtHead(head,8);
    head = insertAtHead(head,7);
    head = insertAtHead(head,6);
    head = insertAtHead(head,5);
    head = insertAtHead(head,4);
    head = insertAtHead(head,3);
    head = insertAtHead(head,2);
    head = insertAtHead(head,1);

    print(head);

    head = reverseByK(head,3);
   
    print(head);

    return 0;
}