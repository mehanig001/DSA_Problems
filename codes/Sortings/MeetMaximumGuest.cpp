//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arrival(n);
        vector<ll> departure(n);
    
        for(ll i = 0; i < n; i++){
            cin>>arrival[i];
        }
    
        for(ll i = 0; i < n; i++){
            cin>>departure[i];
        }

        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());


        //We will merge arrival and departure in such a way 
        // if arrival is addded count++ and departure leads to count-- 
        //max count will be the ans

        vector<ll> v(2*n);

        ll i = 0;
        ll j = 0;

        ll k = 0;
        ll ct = 0;
        
        ll maxi = 0;

        while(i < arrival.size() && j < departure.size()){

            if(arrival[i] <= departure[j]){
                v[k++] = arrival[i++];
                ct++;
                maxi = max(maxi, ct);
            }
            else{
                v[k++] = departure[j++];
                ct--;
            }

        }
        //departure wale hi bache honge jyada se jyada aur kya
        
        cout<<maxi<<endl;
    }

    return 0;
}