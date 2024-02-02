//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printSpan(vector<ll> v){
    
    stack<int> s; //will store index of prev greater elements
    s.push(0);
    cout<<"1 ";//span = 1 for the first element

    for(ll i = 1; i < v.size(); i++){
        while(!s.empty() && v[s.top()]<=v[i]){
            s.pop();
        }
        if(s.empty())cout<<i+1<<" ";
        else{
            cout<<i-s.top()<<" ";
        }
        s.push(i);
    }

    cout<<endl;


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        printSpan(v);
    
    }


    return 0;
}

/*

I/P
1
6
60 10 20 15 35 50

O/P
1 1 2 1 4 5
*/