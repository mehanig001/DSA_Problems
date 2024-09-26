//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

bool equals(ll arr[], ll arr2[]){
    for(ll i = 0; i < 256; i++){
        if(arr[i] != arr2[i])return false;
    }
    return true;
}

bool isPresent(string str, string pattern, ll n, ll m){

    //Precompute freq arrays for first window and pattern
    ll freq_pt[256] = {0};
    ll freq_win[256] = {0};

    for(ll i = 0; i < m; i++){
        freq_pt[pattern[i]]++;
        freq_win[str[i]]++;
    }

    bool ans = (equals(freq_pt,freq_win));
    if(ans == 1)return true;

    for(ll i = m; i < n; i++){
        freq_win[str[i]]++;
        freq_win[str[i-m]]--;
        if(equals(freq_pt,freq_win)){ans = 1;break;}
    }

    return ans;

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

        cout<<isPresent(str,pattern,n,m)<<endl;
    
         
    
    }

    return 0;
}