//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void mergeIntervals(vector<pair<ll,ll>> &v){

    sort(v.begin(),v.end());

 
    for(ll i = 1; i < v.size(); i++){
        if(v[i-1].second >= v[i].first){
            v[i-1].second = max(v[i-1].second,v[i].second);
            v.erase(v.begin()+i,v.begin()+i+1);
            //can be optimized as use a k as iterator and swap merged and inc k accordingly finally arr is merged up to k 
            i--;

        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i].first;
            cin>>v[i].second;
        }

        mergeIntervals(v);
         
        for(auto val: v){
            cout<<val.first<<" "<<val.second<<"  ";
        }
        cout<<endl;
        
         
    
    }

    return 0;
}

/*
2
4
1 3  2 4  5 7  6 8
5
7 9  6 10  4 5  1 3  2 4

o/p
1 4  5 8  
1 5  6 10

*/