//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

vector<ll> spiral(vector<vector<ll>> v, ll m, ll n){

    // TC: THETA(M*N)
    
    vector<ll> ans;

    ll top = 0, bottom = m-1, left = 0, right = n-1;

    while(top<=bottom && left<=right){


        //top
        for(ll j = left; j <= right; j++){
            ans.push_back(v[top][j]);
        }
        top++;
        if(m == 1)return ans;

        //right
        for(ll i = top; i <= bottom; i++){
            ans.push_back(v[i][right]);
        }
        right--;
        if(n == 1)return ans;

        //bottom
        for(ll j = right; j >= left; j--){
            ans.push_back(v[bottom][j]);
        } 
        bottom--;

        //left
        for(ll i = bottom; i >= top; i--){
            ans.push_back(v[i][left]);
        }
        left++;

    }

    return ans;
    
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

        vector<ll> ans = spiral(v,m,n);

        for(auto val: ans){
            cout<<val<<" ";
        }
        cout<<endl;
        
         
    
         
    
    }

    return 0;
}