//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Stack{
    public:
    queue<int> q;

    bool empty(){
        return q.empty();
    }

    int pop(){
        if(q.empty())return -1;
        int b = q.front();
        q.pop();
        
        return b;
    }

    void push(int x){
        queue<int> q2;
        q2.push(x);

        while(!q.empty()){
            ll b = q.front();
            q.pop();
            q2.push(b);
        }

        swap(q,q2);
    }

    int top(){
        return q.front();
    }


};
void print(Stack s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);


    s.pop();

    print(s);


    return 0;
}