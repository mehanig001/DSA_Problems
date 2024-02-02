#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};
struct Stack{
    Node* head;
    int size;
    Stack(){
        head = NULL;
        size = 0;
    }
    void push(int x){
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop(){
        if(head == NULL)return -1;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete(temp);
        size--;
        return res;
    }
    int peek(){
        return (head == NULL?-1:head->data);
    }
    int sz(){return size;}
    bool empty(){
        return size == 0;
    }


};

void printStack(Stack s){
    while(!s.empty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
   

    s.pop();
    s.pop();

    printStack(s);

    //do bar printStack lagao to dikkat kar raha hai n


    return 0;
}