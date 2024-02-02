//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Stack{
    int cap;
    int *arr;
    int top;

    public:

    Stack(int c){
        cap = c;
        top = -1;
        arr = new int(cap);
    }

    void push(int d){
        if(top == cap-1){
            cout<<"Stack is already full";
            return;
        }
        top++;
        arr[top] = d;
        
    }
    void pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
        }
        top--;
    }
    int peek(){
        if(top != -1)
        return arr[top];
        else return INT_MIN;
    }
    bool isEmpty(){
        return top == -1;
    }
    int size(){
        return top+1;
    }


};

void printStack(Stack s){
    while(!s.isEmpty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);

    s.pop();

    printStack(s);

    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    printStack(s);

    return 0;
}

/*
O/P

3 2 1 
3
0

*/