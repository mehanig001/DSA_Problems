//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll median(vector<vector<ll>> &v, ll m, ll n){
    //assuming total no elements = odd
    ll medpos = (m*n+1)/2;

    //all rows are sorted
    ll mini = v[0][0],maxi = v[0][n-1];

    for(ll i = 0; i < m; i++){
        mini = min(mini,v[i][0]);
        maxi = max(maxi,(v[i][n-1]));
    }

    while(mini < maxi){
        ll mid = mini + (maxi-mini)/2;

        
        ll midpos = 0; //pos of mid in 1D sorted arr
        for(ll i = 0; i < m; i++){
            midpos += (upper_bound(v[i].begin(),v[i].end(),mid)-v[i].begin()) ;
        }

        if(midpos == medpos){
            maxi = mid;
        }
        else if(midpos > medpos){
            maxi = mid;
        }
        else{
            mini = mid+1;
        }
    }
    return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    while(t--){

        ll m,n;
        cin>>m>>n;

        vector<vector<ll>> v(m,vector<ll>(n,0));
        
            for(ll i = 0; i < m; i++){
                for(ll j = 0; j < n; j++){
                    cin>>v[i][j];

                }
            }
     
            ll ans = median(v,m,n);

        
            cout<<ans<<endl;
    }
        
         

    return 0;
}
/*

I/P
2

3 3
1 2 3
4 5 6
7 8 9

3 5
5 10 20 30 40
1 2 3 4 6
11 13 15 17 19


O/P
5
11

*/