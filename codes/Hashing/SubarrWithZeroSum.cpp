//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


//NAIVE SOLn O(Nsq)

// bool subarrWithZeroSum(vector<ll> &v){
//     ll n = v.size();
//     for(ll i = 0; i < n-1; i++){
//         ll sum = v[i];
//         for(ll j = i+1; j < n; j++){
//             if(sum == 0 || sum+v[j] == 0)return true;
//             else sum+= v[j];
//         }
//     }
//     return false;
// }




//Master's Solution O(N) 
//Prefix Sum

bool subarrWithZeroSum(vector<ll> &v){
    vector<ll> pre(v.size());
    pre[0] = v[0];
    for(ll i = 1; i < v.size(); i++){
        pre[i] = v[i]+pre[i-1];
    }

    //If any of the values in prefix sum array is repeating it means there exist a subarray with sum as zero
    //only then it is possible to have same prefix val

    unordered_set<ll> s;

    for(auto val : pre){
        if(s.find(val) != s.end() || val == 0){
            return true;
        }
        s.insert(val);
    }
    return false;
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
    
        cout<<subarrWithZeroSum(v)<<endl; 
    
    }

    return 0;
}