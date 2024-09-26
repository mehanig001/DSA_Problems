//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Stack{
    vector<int> v;

    public:
    void push(int x){v.push_back(x);}
    void pop(){v.pop_back();}
    int peek(){return v.back();}
    int size(){return v.size();}
    bool empty(){return v.empty();}
};


void printStack(Stack s){
    while(!s.empty()){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    printStack(s);
    s.pop();
    s.pop();
    printStack(s);

    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;

    


    return 0;
}

/*

O/P
1 2 3 4 
3 4
2
0
*/