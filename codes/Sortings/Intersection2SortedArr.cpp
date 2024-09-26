//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void intersectionOfSortedArrays(vector<ll> &v1, vector<ll> &v2){

    ll prev = -1;
    //instead of prev what we can do is 
    //chk if v1[i] == v1[i-1] then i++; skip repeated item 

     

    ll i = 0; //itr for v1
    ll j = 0; //itr for v2

    while(i < v1.size() && j < v2.size()){

        if(v1[i] == v2[j] && v1[i] != prev){
            cout<<v1[i]<<" ";
            prev = v1[i];
            i++;
            j++;
        }

        if(v1[i] < v2[j])i++;

        else j++;
    }


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> v1(n);
        vector<ll> v2(m);
    
        for(ll i = 0; i < n; i++){
            cin>>v1[i];
        }
        for(ll i = 0; i < m; i++){
            cin>>v2[i];
        }
    
        intersectionOfSortedArrays(v1,v2); 
    
    }

    return 0;
}