//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

// //NAIVE O(Nsq)
// ll longestSubarrWithGivenSum(vector<ll> &v, ll sum){
//     ll ans = 0;

//     for(ll i = 0; i < v.size(); i++){
//         ll curr = 0;
//         for(ll j = i; j < v.size(); j++){
//            curr += v[j];
//            if(curr == sum){
//                 ans = max(ans,j-i+1);
//            }
//         }
//     }
    

//     return ans;
// }



// //O(NlogN)  AS O(N)for pre //not give true result always if pre is not sorted
// ll longestSubarrWithGivenSum(vector<ll> &v, ll sum){
//     ll ans = 0;

//     vector<ll> pre(v.size());
//     pre[0] = v[0];
//     for(ll i = 1; i < v.size(); i++){
//         pre[i] = v[i]+pre[i-1];
//     }


//     for(ll i = 0; i < pre.size(); i++){
//         if(pre[i] == sum){
//             ans = max(ans,i+1);
//         }
      
//             ll si = 0, ei = i-1, idx = -1;
//             while(si <= ei){
//                 ll mid = si + (ei-si)/2;
//                 if(pre[mid] == pre[i]-sum){
//                     idx = mid;
//                     ei = mid-1;
//                 }
//                 else if(pre[mid] > pre[i]-sum){
//                     ei = mid-1;
//                 }
//                 else{
//                     si = mid+1;
//                 }
//             }
//             if(idx != -1)
//             ans = max(ans,i-idx);

        
//     }


//     return ans;
// }

//O(N)  AS O(N)for pre and map
ll longestSubarrWithGivenSum(vector<ll> &v, ll sum){
    ll ans = 0;

    vector<ll> pre(v.size());
    pre[0] = v[0];
    for(ll i = 1; i < v.size(); i++){
        pre[i] = v[i]+pre[i-1];
    }

    unordered_map <ll,ll> m;


    for(ll i = 0; i < pre.size(); i++){
        if(pre[i] == sum){
            ans = max(ans,i+1);
        }
        if(m.find(pre[i]-sum) != m.end()){
            auto it = m.find(pre[i]-sum);
            ans = max(ans,i-it->second);
        }
        if(m.find(pre[i]) == m.end()){
            m.insert({pre[i],i}); //coz we wan leftmost
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
        ll n,sum;
        cin>>n>>sum;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    

        cout<<"length is: "<<longestSubarrWithGivenSum(v,sum)<<endl; 
    
    }

    return 0;
}