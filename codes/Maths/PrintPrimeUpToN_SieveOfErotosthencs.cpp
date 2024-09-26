//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void printPrimes(ll n){
    //visited type boolean array with initial values false
    vector<bool> visited(n+1,1);
    for(ll i = 2; i*i <= n; i++){
        if(visited[i] == 1){
    
            for(ll j = i*2; j <= n; j+=i){
                visited[j] = 0;
            }
        }
    }
    for(ll i = 2; i <= n; i++){
        if(visited[i] == 1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        printPrimes(n);
//         100
// 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
    }

    return 0;
}