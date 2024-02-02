//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> nextGreater(vector<ll> &v, ll n){
    vector<ll> ans;
    stack<ll> s;
    s.push(n-1);
    ans.push_back(-1);

    for(ll i = n-2; i >= 0; i--){
        while(!s.empty() && v[s.top()] <= v[i])s.pop();

        if(s.empty())ans.push_back(-1);
        else ans.push_back(v[s.top()]);

        s.push(i);
    }
    reverse(ans.begin(), ans.end());
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
    
        vector<ll> ans = nextGreater(v,n);

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

O/P
-1 20 35 35 50 -1

*/

