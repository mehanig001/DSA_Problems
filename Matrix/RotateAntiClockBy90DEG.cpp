//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void transpose(vector<vector<ll>> &v, ll m, ll n){
    for(ll i = 0; i < m; i++){
        for(ll j = i+1; j < n; j++){
            //i+1 kyuki sbko swap krenge to waps whi mil jayega
            swap(v[i][j],v[j][i]);
        }
    }
}

void rotate(vector<vector<ll>> &v, ll m, ll n){
    transpose(v,m,n);

    //ab col wise swap kr do 
    for(ll i = 0; i < m; i++){

        ll si = 0;
        ll ei = n-1;

        while(si<ei){
            // swap(v[i][si],v[i][ei]); for clockwise
            swap(v[si][i],v[ei][i]);
            si++;
            ei--;
        }

        
    }
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

        rotate(v,m,n);

        
        for(ll i = 0; i < m; i++){
            for(ll j = 0; j < n; j++){
                cout<<v[i][j]<<" ";

            }
            cout<<endl;
        }
         
        cout<<endl;
         
    
    }

    return 0;
}

/*

2

3 3
1 2 3 
4 5 6 
7 8 9

4 4
1 2 3 4 
6 5 4 7
7 4 5 2
1 9 2 6



O/P
3 6 9 
2 5 8 
1 4 7 

4 7 2 6 
3 4 5 2 
2 5 4 9 
1 6 7 1

*/