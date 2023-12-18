//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void bubbleSort(vector<ll> &v){
    
    // Bubble Sort -> Stable soting algo

    for(ll i = 0; i < v.size()-1; i++){
        bool isSwapped = 0;
        for(ll j = 0; j < v.size()-1-i; j++){
            if(v[j+1]<v[j]){
                swap(v[j+1],v[j]);
                isSwapped = 1;
            }
        }
        if(isSwapped)break;
    }

    //GAUTAM'S Sort Dec Order
    
    // for(ll i = 0; i < v.size(); i++){
    //     for(ll j = i; j < v.size(); j++){
    //         if(v[j]>v[i]){
    //             swap(v[i],v[j]);
    //         }
    //     }
    // } 


    //GAUTAM'S Sort Inc Order
    // for(ll i = 0; i < v.size(); i++){
    //     for(ll j = 0; j < i; j++){
    //         if(v[j]>v[i]){
    //             swap(v[i],v[j]);
    //         }
    //     }
    // } 
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
    
        bubbleSort(v);

        for(auto val:v){
            cout<<val<<" ";
        } 
        cout<<endl;
    
    }

    return 0;
}