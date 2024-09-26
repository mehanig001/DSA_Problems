//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll power(ll n, ll x){
    if(x==0)return 1;
    ll half = power(n,x/2);
    if(x&1){
        return n*half*half;
    }
    else{
        return half*half;
    }
    
}

//by using binary
//3pow10 = 3pow8 * 3pow2 
//   1010 bin of 10 where 1 occ multiply with ans
ll power2(ll n, ll x){
    ll ans = 1;
    while(x>0){
        if(x&1){
            ans *= n;
        }
        n*= n;
        
        x = x>>1;
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,x;
        cin>>n>>x;
        
        cout<<power(n,x)<<endl;

        cout<<power2(n,x)<<endl;
    
    }

    return 0;
}