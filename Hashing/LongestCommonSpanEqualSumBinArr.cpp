//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll maxPossible(vector<ll> &a, vector<ll> &b,ll n){
    //NAIVE is to take every subarr possible in first arr and chk if its sum is equal for the same subarray in 2nd arr or not

    //Master's Solution

    vector<ll> v(n);

    for(ll i = 0; i < v.size(); i++){
        v[i] = a[i]-b[i];
    }

    //Now we will find the longest subarray in v possible with sum equal to zero

    vector<ll> pre(n);
    pre[0] = v[0];

    for(ll i = 1; i < n; i++){
        pre[i] = pre[i-1] + v[i];

    }

    unordered_map<ll,ll> m;
    ll ans = 0,sum = 0;

    for(ll i = 0; i < n; i++){
        if(pre[i] == sum){
            ans = max(ans,i+1);
        }

        if(m.find(pre[i]-sum) != m.end()){
            auto it = m.find(pre[i]-sum);
            ans = max(ans,i-it->second);
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
        vector<ll> a(n);
        vector<ll> b(n);
    
        for(ll i = 0; i < n; i++){
            cin>>a[i];
        }
    
        for(ll i = 0; i < n; i++){
            cin>>b[i];
        }

        cout<<maxPossible(a,b,n)<<endl;
    
         
    
    }

    return 0;
}

/*
I/P
4
7
1 0 1 1 0 0 0
0 0 1 0 1 0 0

3
0 0 0
1 1 1

2
1 0
0 0

1
0 
1



O/p
6
0
1
0

*/