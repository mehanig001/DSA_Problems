//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> prevGreater(vector<ll> &v, ll n){
    vector<ll> ans;
    stack<ll> s;
    s.push(0);
    ans.push_back(-1);

    for(ll i = 1; i < n; i++){
        while(!s.empty() && v[s.top()] >= v[i])s.pop();

        if(s.empty())ans.push_back(-1);
        else ans.push_back(v[s.top()]);

        s.push(i);
    }

    return ans;
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
    
        vector<ll> ans = prevGreater(v,n);

        for(auto val: ans)cout<<val<<" ";
        cout<<endl;
    
    }


    return 0;
}

/*
I/p
1
6
60 10 20 15 35 50

O/p
-1 60 60 20 60 60
*/