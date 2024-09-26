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
        ll n;
        cin>>n;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        unordered_set<ll> s(v.begin(),v.end());
        ll ctr = 1,ans = 1;

        for(auto val: s){
            if(s.find(val-1) == s.end()){
                //Means it is the begining element for a valid consecutive subseq
                while(s.find(val+ctr) != s.end()){
                    ctr++;
                }
                ans = max(ctr,ans);
            }
            ctr = 1;
        }

        cout<<ans<<endl;
    
    }

    return 0;
}