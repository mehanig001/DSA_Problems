//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void selectionSort(vector<ll> &v){

    for(ll i = 0; i < v.size(); i++){
        ll currSmallestIdx = i;
        ll curr = v[i];
        for(ll j = i+1; j < v.size(); j++){
            if(v[j] < v[i]){
                currSmallestIdx = j;
            }
        }
        swap(v[i],v[currSmallestIdx]);

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

        selectionSort(v);

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}