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
        ll n,sum;
        cin>>n>>sum;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        unordered_set<ll> s(v.begin(),v.end());

        bool ans = 0;


        for(ll i = 0; i < n; i++){
            ll curr = v[i];
            
            s.erase(curr);

            if(s.find(sum-curr) != s.end()){
                ans = 1;
                break;
            }
        } 

        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    
    }

    return 0;
}