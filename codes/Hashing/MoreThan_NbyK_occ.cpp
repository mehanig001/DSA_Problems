//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        // unordered_map<ll,ll> m;

        // for(auto val : v){
        //     m[val]++;
        // }

        // for(auto pr : m){
        //     if(pr.second > (n/k)){
        //         cout<<pr.first<<" ";
        //     }
        // }
        // cout<<endl;

        //Another approach for O(n*k) useful when k <<< n 
        //map me jgh kam ho to

        unordered_map<ll,ll> m;

        for(ll i = 0; i < n; i++){

            if(m.find(v[i]) != m.end()){
                m[v[i]]++;
            }

            else if(m.size() < k){
                m.insert({v[i],1});
            }
            else{
                auto it = m.begin();
                while(it != m.end()){
                    if(it->second == 1){
                        m.erase(it);
                       
                    }
                    else{
                        (it->second)--;
                    }
                    it++;
                }
            }

        }
        for(auto val : m){
            val.second = 0;
            for(ll i = 0; i < n; i++){
                if(v[i] == val.first){
                    val.second++;
                }
            }
            if(val.second > n/k)cout<<val.first<<" ";
        }
        cout<<endl;
    
    }

    return 0;
}

/*
I/P
1
9 4
30 10 20 20 20 10 40 30 30

O/P
20 30
*/