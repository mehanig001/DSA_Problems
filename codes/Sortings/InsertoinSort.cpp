//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void insertionSort(vector<ll> &v){

    for(ll i = 1; i < v.size(); i++){

        ll curr = v[i];
        ll prev = i-1;

        while(prev>=0 && curr < v[prev]){
            v[prev+1] = v[prev];
            prev--;
        }

        v[prev+1] = curr;

    }
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

        insertionSort(v);

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}