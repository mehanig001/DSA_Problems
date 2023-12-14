//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,sum;
        cin>>n>>sum;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }

        //to return whether there is a pair with given sum in array or not

        ll l = 0;
        ll r = n-1;

        bool ans = 0;
        while(l<r){
            if(v[l] + v[r] == sum){
                ans = 1;
                break;
            }
            else if(v[l] + v[r] > sum)r--;
            else l++;
        }
        if(ans)cout<<"YES"<<endl;
        else 
        cout<<"NO"<<endl;
    
    
    }

    return 0;
}
/*
I/P
2
5 17
1 3 4 5 6
6 2
1 1 2 3 7 8

O/P
NO
YES
*/