//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long


//when only positive numbers are allowed
// class Stack{
//     vector<int> v;
//     int mini = INT32_MAX;

//     public:
//     void push(int x){
//         if(v.empty()){
//             v.push_back(x);
//         }
//         else if(x < mini){
//             v.push_back(x-mini);
//             mini = x;
//         }
//         else{
//             v.push_back(x);
//         }
//     }
//     void pop(){
//         if(v.empty())return;
//         if(v.back()<0){
//             mini = mini-v.back();
//         }
//         v.pop_back();
//     }
//     int peek(){
//         return (v.back()>0?v.back():mini);
//     }


//     int size(){return v.size();}
//     bool empty(){return v.empty();}
//     int getMin(){return mini;}
// };




class Stack{
    vector<int> v;
    int mini = INT32_MAX;

    public:
    void push(int x){
        if(v.empty()){
            v.push_back(x);
            mini = x;
        }
        else if(x < mini){
            v.push_back(2*x-mini);
            mini = x;
        }
        else{
            v.push_back(x);
        }
    }
    void pop(){
        if(v.empty())return;
        if(v.back()<mini){
            mini = 2*mini-v.back();
        }
        v.pop_back();
    }
    int peek(){
        return (v.back()<mini?mini:v.back());
    }


    int size(){return v.size();}
    bool empty(){return v.empty();}
    int getMin(){return mini;}
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
    cout<<s.getMin()<<endl;
    s.pop();
    cout<<s.getMin()<<endl;

    s.pop();
    cout<<s.getMin()<<endl;

    printStack(s);


    


    return 0;
}

/*

O/P
1 2 3 4 
3 4
2
0
*/