//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


ll countEqualSumSubset(vector<ll> &v, vector<ll> newv, ll i ,int k){
    if(i == v.size()){ 
        if(accumulate(newv.begin(), newv.end(), 0) == k) return 1;
        else return 0;
    }
    vector<ll> newv2 = newv;
    newv2.push_back(v[i]);
    return countEqualSumSubset(v,newv,i+1,k) + countEqualSumSubset(v,newv2,i+1,k);

}

ll countEqualSumSubset(vector<ll> &v, ll k, ll i = 0, ll sum = 0){
   
    if(i == v.size())
        return (sum == k)?1:0;

    return countEqualSumSubset(v,k,i+1,sum) + countEqualSumSubset(v,k,i+1,sum+v[i]);
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
        vector<ll> newv;

        for(ll i = 0; i < n; i++){
        cin>>v[i];
        }
        
        cout<<countEqualSumSubset(v,0,0,0);
    }

    return 0;
}