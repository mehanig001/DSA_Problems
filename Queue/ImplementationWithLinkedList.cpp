//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
    
    int data;
    Node* next;

    Node(){}
    Node(int d){
        data = d;
        next = NULL;
    }

};

class Queue{
    public:
    Node *head, *front, *rear;
    int sz;

    Queue(){
        
        head = NULL;
        front = NULL;
        rear = NULL;
        sz = 0;
    }
    
    int size(){
        return sz;
    }
    bool empty(){
        return sz == 0;
    }
    Node* enque(int d){
        Node* newnode = new Node(d);
        // sz++;
        if(empty()){
            head = newnode;
            front = newnode;
            rear = newnode;
            sz++;
            return head;
        }
        
        rear->next = newnode;
        rear = rear->next;
        sz++;
        return head;

    }
    Node* deque(){
        if(empty()){
            return head;
        }
        sz--;

        Node* temp = head;
        head = head->next;

        //if we head deleted last item we also have to update rear 
        if(head == NULL)rear = NULL;

        delete(temp);
    }


    int getFront(){
        if(empty())return -1;
        return head->data;
    }

    int getRear(){
        if(empty())return -1;
        return rear->data;
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;

    }


};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Queue q;

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);

    q.deque();


    cout<<q.getFront()<<endl;
    cout<<q.getRear()<<endl;
    cout<<endl;
    cout<<q.size()<<endl;
    q.print();

    




    return 0;
}

/*
O/P
2
4

3
2 3 4

*/

