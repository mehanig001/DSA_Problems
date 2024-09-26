//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void print(queue<int> q){
    
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverseItr(queue<int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

void reverseRec(queue<int> &q){
    //man lo n-1 items rev ho chuke hai to pahle wale ko front se hata ke last me hi to lagana hai
    if(q.empty())return;
    int f = q.front();
    q.pop();
    reverseRec(q);
    q.push(f);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    print(q);

    reverseItr(q);
    print(q);

    reverseRec(q);
    print(q);



    return 0;
}

/*
O/P
1 2 3 4 5 
5 4 3 2 1 
1 2 3 4 5
*/