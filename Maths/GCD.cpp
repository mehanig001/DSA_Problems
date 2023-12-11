//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

//Property product of two numbers  = gcd * lcm of the same

ll gcd(ll a, ll b){
    ll ans = 1;
    if(b == 0){
        if(a == 0)return 1;
        return a;
    }
    return gcd(b,a%b); //gcd(big,big-small) also valid

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll a,b;
        cin>>a>>b;
        
        cout<<gcd(a,b)<<endl;
    
    }

    return 0;
}