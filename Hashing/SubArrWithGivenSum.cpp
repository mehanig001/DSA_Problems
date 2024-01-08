//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

//naive solution can be same as prev what we will do is we take every element as the begining element of subarray one by one and include further elements with it and check for the required sum 


//optimized using prefix sum  as pre1 + sum = pre2

bool subarrWithGivenSumExist(vector<ll> &v, ll sum){
    vector<ll> pre = v;

    for(ll i = 1; i < pre.size(); i++){
        pre[i]+=pre[i-1];
    }

    // for(auto val: pre)cout<<val<<" ";cout<<endl;
    
    unordered_set<ll> s;
    for(ll i = 0; i < pre.size(); i++){
        if(pre[i] == sum)return true;
        if(s.find(pre[i]-sum) != s.end())return true;

        s.insert(pre[i]);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n,sum;
        cin>>n>>sum;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        cout<<subarrWithGivenSumExist(v,sum)<<endl; 
    
    }

    return 0;
}