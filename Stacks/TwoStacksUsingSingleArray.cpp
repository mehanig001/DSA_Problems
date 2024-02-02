//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class TwoStacks{
    int *arr;
    int cap;
    int top1,top2;
    public:

    TwoStacks(int c){
        arr = new int(c);
        cap = c;
        top1 = -1;
        top2 = c;
    }
    void push1(int x){
        if(top1+1 >= top2)return;//space full
        top1++;
        arr[top1] = x;
    }
    void push2(int x){
        if(top1+1 >= top2)return;//space full
        top2--;
        arr[top2] = x;
    }

    int pop1(){
        if(top1 == -1)return -1;
        int temp = arr[top1];
        top1--;
        return temp;
    }
    int pop2(){
        if(top2 == cap)return -1;
        int temp = arr[top2];
        top2++;
        return temp;
    }

    int peek1(){
        return top1 == -1?-1:arr[top1];
    }
    int peek2(){
        return top2 == cap?-1:arr[top2];
    }
    int size1(){
        return top1+1;
    }
    int size2(){
        return cap-top2;
    }
    bool empty1(){
        return top1 == -1;
    }
    bool empty2(){
        return top2 == cap;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    TwoStacks s(10);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push2(5);
    s.push2(6);
    s.push2(7);

    cout<<s.peek1()<<endl;
    cout<<s.peek2()<<endl;
    s.pop1();
    s.pop2();
    cout<<s.size1()<<endl;
    cout<<s.size2()<<endl;

    cout<<s.empty1()<<" "<<s.empty2()<<endl;


    return 0;
}

/*
O/p
3
7
2
2
0 0

*/