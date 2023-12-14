//<-----------------------------SSDN------------------------------>

#include<bits/stdc++.h>
#define ll long long
using namespace std; 
// ll search(vector<ll> &v, ll si, ll ei, ll k){
//     ll mid = si + (ei-si)/2;

//     if(si>ei)return -1;

//     if(v[mid] == n k){
//         return mid;
//     }

//     if(k>=v[si] && k < v[mid]){  //Isko samjh lo with drawing lines or graph v[0] ka role rotated array me
//         search(v,si,mid-1,k);
//     }
//     else{
//         search(v,mid+1,ei,k);
//     }
// }


//Iterative approach
ll search(vector<ll> &v, ll si, ll ei, ll k){
    ll mid = si + (ei-si)/2;

    while(si<=ei){
        mid = si + (ei-si)/2;
        if(v[mid] == k){
            return mid;
        }

        if(v[mid]>k && k>=v[si]){
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }
    return -1;
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

        cout<<search(v,0,n-1,k)<<endl; 
    
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

O/P
2 
-1

*/