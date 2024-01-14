//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll fact(ll n){
    return (n == 0 || n == 1)?1:n*fact(n-1);
}

ll lexographicOrder(string str, ll n){
    //right me kitne chote hai kaise calc kre
    ll count[256] = {0};
    //first loop 
    for(ll i = 0; i < n; i++){
        count[str[i]]++;
    }

    //second loop prefix of count which tells overall number of lesser characters for a given ch present in string
    for(ll i = 1; i < 256; i++){
        count[i]+=count[i-1];
    }
    //then one by one as we processed an element we will decrease all counts by 1 to have right me smaller values
     
    ll mul = fact(n);
    ll ans = 0;

    for(ll i = 0; i < n-1; i++){
        mul = mul/(n-i); //5fac 4fac 3fac 2fac 1fac 0 fac  for n = 6
        ans += mul*count[str[i]-1];
        //dec count of next elements i.e. remove curr leftmost proceseed element
        for(ll j = str[i]; j < 256; j++){
            count[j]--;
        }


    }
    return ans+1;
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        string str;
        cin>>str;
        cout<<lexographicOrder(str,n)<<endl;
         
    
    }

    return 0;
}