//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void bucketSort(vector<ll> &v, ll k){

    vector<vector<ll>> b(k);

    ll maxi = *(max_element(v.begin(), v.end()));
    maxi++;

    
    for(ll i = 0; i < v.size(); i++){
        //placing items in respective buckets according to uniform distribution between 0 to maxi
        ll bi = (k*v[i])/maxi; // bucket idx 

        b[bi].push_back(v[i]);
    }
    
    // sort individual buckets
    for(ll i = 0; i < k; i++){
        sort(b[i].begin(), b[i].end());
    }

    //copy elements to the original array
    ll idx = 0;

    for(ll i = 0; i < k; i++){
        for(ll j = 0; j < b[i].size(); j++){
            v[idx++] = b[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,k; //k = no of buckets
        cin>>n>>k;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }

        bucketSort(v,k);
    
        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}