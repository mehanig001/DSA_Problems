//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll longestSubarrWithEqual0sAnd1sBinaryArr(vector<ll> v){
    ll n = v.size();
    //NAIVE is to consider every subarr possible with equal 0 and 1 ct and return maxlength

    //Master's Approach

    //Step 1: Replace all 0s by -1s
    for(ll i = 0; i < n; i++){
        if(v[i] == 0){
            v[i] = -1;
        }
    }

    //Step 2: Now find max length subarray possible with sum as 0
    ll ans = 0;

    //Prefix Sum
    vector<ll> pre(n);
    pre[0] = v[0];
    for(ll i = 1 ; i < n; i++){
        pre[i] = pre[i-1] + v[i];
    }

    unordered_map<ll,ll> m;//to store leftmost occurance of distinct prefixes

    for(ll i = 0; i < n; i++){
        if(pre[i] == 0){
            ans = max(ans,i+1);
        }
        if(m.find(pre[i] - 0) != m.end()){
            auto itr = m.find(pre[i]-0);
            ans = max(ans,i-(itr->second));

        }

        if(m.find(pre[i]) == m.end()){
            m.insert({pre[i],i});
        }
    }

    return ans;


} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        cout<<longestSubarrWithEqual0sAnd1sBinaryArr(v)<<endl; 
    
    }

    return 0;
}