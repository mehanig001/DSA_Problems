//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    dq.push_front(4);
    dq.push_front(5);

    for(auto val : dq){
        cout<<val<<" ";
    }
    cout<<endl;

    dq.pop_front();

    auto it = dq.begin();
    it++;
    dq.insert(it,10);

    
    

    for(auto val : dq){
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}