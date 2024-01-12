//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

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

        vector<ll> freq(256,0);


        //2 TRAVERSAL METHOD


        // for(ll i = 0; i < n; i++){
        //     freq[str[i]]++;
        // }

        // bool present = 0;

        // for(ll i = 0; i < n; i++){
        //     if(freq[str[i]] == 1){
        //         present = 1;
        //         cout<<i<<endl;
        //         break;
        //     }
        // }
        // if(!present)cout<<"No non rep char found"<<endl;


        //SINGLE TRAVERSAL OF STRING

        vector<ll> firstIdx(256,-1);

        for(ll i = 0; i < n; i++){
            if(firstIdx[str[i]] == -1){
                firstIdx[str[i]] = i;
            }
            else{
                firstIdx[str[i]] = -2;

            }
        }
        ll ans = n;

                    //constant size traversal
        for(ll i = 0; i < 256; i++){
            if(firstIdx[i]!= -1 && firstIdx[i]!=-2){
                ans = min(ans,firstIdx[i]);
            }
        }
        
        if(ans != n){
            cout<<ans<<endl;
        }
        else{ 
            cout<<"No non rep char found"<<endl;
        }
         
    
    }

    return 0;
}

/*
4
6
gautam
6
abcbca
3
abb
13
geeksforgeeks


0
No non rep char found
0
5


*/