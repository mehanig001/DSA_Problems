//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

//NAIVE IS IN O(Ncube)where we will take max of length of each substrings possible only with all unique characters

//O(NSq) we will maintain a visited array to check uniqueness
ll largestUniqueSubstring(string str, ll n){
    
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        vector<bool> visited(256);
        for(ll j = i; j < n; j++){
            if(visited[str[j]] == true){
                break;
            }
            else{
                ans = max(ans,j-i+1);
                visited[str[j]] = true;
            }
        }
    }
    return ans;
}


/*


//O(N) EFFICIENT SOL-------------------------------------------------
ll largestUniqueSubstring(string str, ll n){
    //we will precompute a prevRightmostIdx for every char
    //idx j  0 1 2 3 4 5 6 7 8 9
    //eg FOR a b c a a b a a c d
    //prev   n n n 0 3 1 4 6 2 n   //n = -1  
    //maxEnd 1 2 3 3 1 2 2 1 2 3  // ans will be max of these values
    vector<ll> prev(256,-1);
    ll ans = 0;
    ll i = 0;

    for(ll j = 0; j < n; j++){
        i = max(i,prev[str[j]]+1);
        ll maxEnd = j-i+1;
        ans = max(ans,maxEnd);
        prev[str[j]] = j;
    }
    return ans;
}
//------------------------------------------------------------------------

*/

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

        ll ans = largestUniqueSubstring(str,n);

        cout<<ans<<endl;
    
         
    
    }

    return 0;
}