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

    return -1;
}

bool isSorted(vector<ll> v){
    for(ll i = 0; i < v.size()-1; i++){
        if(v[i]>v[i+1])return false;
    }
    return true;
}

ll search(vector<ll> v, ll si, ll ei, ll k){
    ll mid = si + (ei-si)/2;
    if(si>ei)return -1;

    if(v[mid] == k)return mid;
    
    if(v[mid] > v[0] && k >= v[0] && k<=v[mid]){
        //left part is sorted
        search(v,si,mid,k);
    }
    else{
        search(v,mid+1,ei,k);
    }
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

        cout<<search(v,0,v.size()-1,k)<<endl;
    
    }

    return 0;
}

/*
I/P
2
7 30
10 20 30 40 50 8 9
5 40
100 200 300 10 20
5 4
9 8 4 3 1 

O/P
2 
-1
2

*/