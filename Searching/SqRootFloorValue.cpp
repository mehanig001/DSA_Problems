//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll sqrt(ll n){
    ll ans = 1;
    
    ll si = 1;
    ll ei = n;

    while(si <= ei){
        ll mid = si + (ei-si)/2;
        if(mid*mid == n){
            return mid;
        }
        else if(mid*mid > n){
            ei = mid-1;
        }
        else{
            ans = mid;
            si = mid+1;
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;

        cout<<sqrt(n)<<endl;    
         
    
    }

    return 0;
}