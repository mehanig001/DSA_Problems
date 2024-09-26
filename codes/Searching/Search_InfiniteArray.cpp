//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll binarySearch(vector<ll> &v, ll si, ll ei,ll k){
    ll mid = si + (ei-si)/2;

    while(si<=ei){
        mid = si+(ei-si)/2;
        if(v[mid] == k){
            return mid;
        }
        else if(v[mid]>k){
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }
}

ll search(vector<ll> &v, ll n, ll k){
    ll si = 0;
    ll ei = 1;

    if(v[si] == k)return si;

    while(v[ei] < k){
        ei*=2;
    }

    if(v[ei] == k)return ei;

    // return binarySearch(v,si,ei,k);
    return binarySearch(v,ei/2,ei,k);

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        cout<<search(v,n,k)<<endl; 
    
    }

    return 0;
}

/*
I/P
1
9 4
1 2 2 4 5 7 7 8 9 

O/p
3
*/