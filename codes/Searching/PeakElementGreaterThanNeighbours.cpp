//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll findPeak(vector<ll> &v, ll si, ll ei){
    //Rec
    ll n = v.size();
    if(si>ei)return -1; //no peak found
    if(n == 1)return v[0];
    if(v[0]>v[1])return v[0];
    else if(v[n-1] > v[n-2])return v[n-1];


    ll mid = si + (ei-si)/2;

    if((v[mid-1]<=v[mid])&&(v[mid]>=v[mid+1])){
        return v[mid];
    }
    else if(v[mid] < v[si]){
        findPeak(v,si,mid-1);
    }
    else{
        findPeak(v,mid+1,ei);
    }

    // else if(v[mid-1]>v[mid]){
    //     findPeak(v,si,mid-1);
    // }
    // else{
    //     findPeak(v,mid+1,ei);
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
    
        cout<<findPeak(v,0,n-1)<<endl; 
    
    }
    /*
    I/P

    */
    return 0;
}