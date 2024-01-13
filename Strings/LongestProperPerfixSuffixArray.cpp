//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


//NAIVE  O(Ncube)--------------------------------------------------------------------------------
ll longPropPreSuff(string str, ll n){
    for(ll len = n-1; len>0; len--){
        bool flag = true;
        for(ll i = 0; i < len; i++){
            if(str[i] != str[n-len+i]){
                flag = false;
            }

        }
        if(flag){
            return len;
        }
    }
    return 0;
}
void fill_LPS(string str, ll n,vector<ll> &lps){
    for(ll i = 0; i < n; i++){
        lps[i] = longPropPreSuff(str,i+1);
    }
}
// -----------------------------------------------------------------------------------------------

//Efficient Solution we will find val of lps[i] using values from lps[0] to lps[i-1]

void fill_LPS_Efficient(string str, ll n, vector<ll> &lps){


    lps[0] = 0; //always
    ll i = 1, len = 0;
    
    while(i < n){
        //Case1
        if(str[i] == str[len]){
            lps[i] = len+1;
            len++;
            i++;
        }

        else{
            //str[i]!= str[len]

            //CASE 2.a
            if(len == 0){
                lps[i] = 0;  
                i++;
            }
            else{
                //CASE: 2.b
                len = lps[len-1];
                //we will not increment i till any of conn 1 or 2a reaches
                

            }

        }
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
        string str;
        cin>>str;

        vector<ll> lps(n);

        // fill_LPS(str,n,lps);
        fill_LPS_Efficient(str,n,lps);

        for(auto val: lps){
            cout<<val<<" ";
        }
        cout<<endl;
        
         
    }

    return 0;
}