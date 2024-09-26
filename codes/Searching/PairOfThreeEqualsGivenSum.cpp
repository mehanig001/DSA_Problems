//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

bool isPairExist(vector<ll> v, ll sum){
    //O(nsq)
        ll l = 0;
        ll r = v.size()-1;
    for(ll i = 0; i < v.size (); i++){
        ll fixed = v[i];

        while(l<r){
            if(l == i)l++;
            if(r == i)r--;

            if(fixed + v[l] + v[r] == sum){
                cout<<fixed<<" "<<v[l]<<" "<<v[r]<<endl;
                return true;
            }

            else if(fixed + v[l] + v[r] > sum)r--;
            else l++;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,sum;
        cin>>n>>sum;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        cout<<isPairExist(v,sum)<<endl;
    
    }

    return 0;
}