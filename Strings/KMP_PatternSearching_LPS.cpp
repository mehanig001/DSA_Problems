
//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


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

void kmp(string str, string pattern, ll n, ll m){
    vector<ll> lps(m);
    fill_LPS_Efficient(pattern,pattern.length(),lps);

    ll i = 0, j = 0;
    while(i < n){
        if(str[i] == pattern[j]){
            i++;
            j++;
        }
        if(j == m){
            //pattern found
            cout<<i-m<<" ";
            j = lps[m-1]; //shift pattern accordingly to check for next pattern

        }
        else if(i < n && pattern[j] != str[i]){
            if(j == 0)i++;
            else j = lps[j-1];
        }
    }
    cout<<endl;

}




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        string str,pattern;
        cin>>str>>pattern;

        kmp(str,pattern,n,m);
    
         
    
    }

    return 0;
}