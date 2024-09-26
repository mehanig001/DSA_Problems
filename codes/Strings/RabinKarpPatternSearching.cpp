//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


//TC still O((N-M+1)*M) int worst case "AAAAA" for "AAA" but generally performs better than Naive sol on avg


void rbSearch(string str, string pattern, ll n, ll m){
    if(n < m)return;

    // Let d be constant for weighted sum 
    ll d = 5; //let

    //Since hash value can be very large we have to take a modulo with q of val calc
    //Chose q as a prime and a large no so that we will match minimum windows for pattern searching
    ll q = 10001;

    //Computing h = pow(d,m-1)%q
    ll h = 1; 
    for(ll i = 1; i < m; i++){
        h = (h*d)%q;
    }


    //Pre Compute hash function for first window as t and pattern p
    ll t = 0, p = 0;

    for(ll i = 0; i < m; i++){
        p = (p*d + pattern[i])%q;  
        t = (t*d + str[i])%q;    // str[0]*pow(d,m-1) + str[1]*pow(d,m-2) + ...... + str[m-1]
    }


    //checking for suspeciouts hit
    for(ll i = 0; i < n-m+1; i++){
        if(p == t){
            bool flag = true;
            for(ll j = 0; j < m; j++){
                if(str[i+j] != pattern[j]){
                    flag = false;
                    break;
                }
            }
            if(flag = true){
                cout<<i<<" ";
            }

        }
        if(i < n-m){
            //calc hash funcn for next window using previous window
            //jaise ki 34256 --> (3425 - 3*1000)*10 + 6 = 4256  //window of 4
            t = ( ((t-str[i]*h)*d + str[i+m]) )%q;
            if(t<=0)t+=q;

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

        rbSearch(str,pattern,n,m);
    
         
    
    }

    return 0;
}