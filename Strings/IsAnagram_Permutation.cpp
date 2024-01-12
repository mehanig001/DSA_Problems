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
        
        string s1,s2;
        cin>>s1>>s2;

        vector<ll> v(256,0);

        // sort(s1.begin(), s1.end());
        // sort(s2.begin(), s2.end());

        // if(s1 == s2){
        //     cout<<"YES"<<endl;
        // }
        // else{
        //     cout<<"NO"<<endl;
        // }

        for(ll i = 0; i < m ; i++){
            v[s1[i]]++;
            v[s2[i]]--;
        }

        bool ans = 1;
        
         

        for(ll i = 0; i < 256; i++){
            
            if(v[i] != 0){
                ans = 0;
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