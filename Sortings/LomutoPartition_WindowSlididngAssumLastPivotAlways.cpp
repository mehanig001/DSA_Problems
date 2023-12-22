//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll lumotoPartition(vector<ll> &v){
    //let pivot element be last else what we can do is swap given idx element with last one and proceed
    ll n = v.size();
    ll pivot = v[n-1];

    //we will maintain left elements as window of smaller elements than pivot
    ll i = -1;

    for(ll j = 0; j < n-1; j++){

        if(v[j] < pivot){
            i++;
            swap(v[i],v[j]);
        }

    }
        swap(v[i+1],v[n-1]);

        return i+1;

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
    
        cout<<lumotoPartition(v)<<endl;

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
         
    
    }

    return 0;
}