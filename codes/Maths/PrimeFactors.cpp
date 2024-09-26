//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void printPrimeFactors(ll n){
    // firstly we print 1, all 2s and 3s
    if(n<=1){
        cout<<endl;
        return;
    }
    cout<<1<<" ";
    while(n%2 == 0){
        n/=2;
        cout<<2<<" ";
    }
    while(n%3 == 0){
        cout<<3<<" ";
        n/=3;
    }
    for(ll i = 5; i <= n; i+=6){ //kyuki except 5i+2, 5i+1 to 5i+5 are either even or mul of 3 always 
        if(n%i == 0){
            cout<<i<<" ";
            n/=i;
        }
        if(n%(i+2) == 0){
            cout<<i+2<<" ";
            n/=(i+2);
        }
    }
    if(n > 3){
        cout<<n<<" ";
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
       
        printPrimeFactors(n);
        cout<<endl;
         
    
    }

    return 0;
}