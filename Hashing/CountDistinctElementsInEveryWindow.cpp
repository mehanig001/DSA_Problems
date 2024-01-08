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
        ll n,k;
        cin>>n>>k; //k is size of window
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }

        unordered_map<ll,ll> m;

        for(ll i = 0; i < k; i++){
            //freq of all elements in 1st window
            m[v[i]]++;

        }
        cout<<m.size()<<" ";

        //every time we are dec the freq count for begining element of window and 
            //if next element is present in map we are inc its freq else we are inserting that with 1
         
        for(ll i = k; i < n; i++){
            if(m[v[i-k]] == 1){
                m.erase(v[i-k]);
            }
            else{
                m[v[i-k]]--;
            }

            m[v[i]]++;
            cout<<m.size()<<" ";

        }
        cout<<endl;
    }

    return 0;
}

/*
I/P
4
6 4
10 20 10 20 30 20
6 3
10 20 10 20 30 20
6 4
10 20 10 10 30 40
6 4
10 20 10 20 10 20

O/P
2 3 3 
2 2 3 2 
2 3 3 
2 2 2
*/