//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

bool isRotated(string str, string str2, ll n){
    //Obvious that length should be same 
    if(str.size()!=str2.size())return false;
    //Rather than rotating and checking we can concatenate str with itself 
    str += str;

    ll idx = str.find(str2);
    if(idx >= 0 && idx < 2*n){
        return true;
    }
    else{
        return false;
    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        string str, str2;
        cin>>str>>str2;



        // //NAIVE SOLUTION O(Nsq)
        // bool ans = 0;

        // string newstr = str;
        // for(ll i = 0; i < n; i++){
        //     if(newstr == str2){
        //         ans = 1;
        //         break;
        //     }

        //     reverse(newstr.begin(),newstr.end());
        //     reverse(newstr.begin(),newstr.end()-1);
        //     // cout<<newstr<<endl;
        // }

        // if(ans)cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;

        //Optimized O(N)
        cout<<isRotated(str,str2,n)<<endl;
         
    
    }

    return 0;
}