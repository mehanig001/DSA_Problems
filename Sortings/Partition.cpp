//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll partition(vector<ll> &v, ll idx){

    //count element less than curr;
    ll ctr = 0;
    ll curr = v[idx];

    for(ll i = 0; i < v.size(); i++){
        if(v[i]<curr && i != idx){
            ctr++;
        }
    }
    ll pvtIdx = ctr;
    swap(v[idx],v[pvtIdx]);

    ll l = 0;
    ll r = v.size();

    while(l < r){
        while(l < ctr && v[l] < curr){
            l++;
        }
        while(r > ctr && v[r] > curr){
            r--;
        }

        swap(v[l],v[r]);
        l++;
        r--;
    }

    return pvtIdx;
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
    
        cout<<partition(v,5)<<endl; 

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
         
    
    }

    return 0;
}