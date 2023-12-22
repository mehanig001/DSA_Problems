//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll Partition(vector<ll> &v, ll l,ll r){
    ll pivot = v[l];
    ll i = l-1;
    ll j = r+1;

    while(true){


        do{
            i++;
        }while(v[i]<pivot);
        do{
            j--;
        }while(v[j]>pivot);


        if(i>=j)return j;

        swap(v[i],v[j]);
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

        
        cout<<Partition(v,0,v.size()-1)<<endl;
    
        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}