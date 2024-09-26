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
        ll n;
        cin>>n;
        
        //means 5 : 120 ans = 1 , 10: 3628800 ans = 2;

        // fact means 1*2*3*4*5*......*n 

        //1 zero can be added by mul 2*5

        //2 are available more times than 5 means for every 5 there exist 2 

        // we have to count no of 5 in series 

        // let n = 100 Ans = 24

        // ans = n/5 + n/pow(5,2) + ..... + 1; 
        ll ans = 0;
        ll i = 1;
        while(n/pow(5,i) >0){
            ans += (n/pow(5,i));
            i++;
          
        }

        cout<<ans<<endl;

         
    
    }

    return 0;
}