//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> v(n);
        vector<ll> v2(m);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        for(ll i = 0; i < m; i++){
            cin>>v2[i];
        }

        unordered_set<ll> s(v2.begin(),v2.end());

        for(ll i = 0; i < n; i++){
            s.insert(v[i]);
        }
        for(auto val: s)cout<<val<<" ";
        cout<<endl;
         
    
    }

    return 0;
}