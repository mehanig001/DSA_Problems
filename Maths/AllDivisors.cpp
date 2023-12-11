//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void printDivisors(ll n){
    ll i;
    for( i = 1; i < sqrt(n); i++){
        if(n%i == 0){
            cout<<i<<" ";
        }
    }
    for(i; i >= 1; i--){
        if((n)%i == 0){
            cout<<(n/i)<<" ";
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
       
        //Example  15: 1 3 5 15
        //in less than O(N)

        //Divisors occur in pair and smaller one always less than or equal to sqrt(n)

        printDivisors(n);
    
    }

    return 0;
}