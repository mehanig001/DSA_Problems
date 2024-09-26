// All elements appear exactly once except repeating element
//all elements from 0 to max<= n-2 are present with repeating 

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
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    

        ll maxi = *max_element(v.begin(), v.end());

        ll ctrep = n-maxi;
        // cout<<ctrep<<endl;

        if(ctrep%2 == 0){
            ll ans = 0;
            for(ll i = 0; i <= maxi; i++){
                ans = ans^i;
            }
            for(ll i = 0; i < n; i++){
                ans = ans^v[i];
            }
            cout<<ans<<endl;
            continue;
        }
        else{
        sort(v.begin(),v.end());

            ll si = 0;
            ll ei = n-1;

            ll ans = 0;
            if(v[0] == v[1]){
                ans = v[0];
            }
            else if(v[n-1] == v[n-2])ans = v[n-1];


            else{
                ll mid = si + (ei-si)/2;

                while(si<=ei){
                    mid = si + (ei-si)/2;

                    if(v[mid] == v[mid-1] || v[mid] == v[mid+1]){
                        ans = mid;
                        break;
                    }
                    else if(v[mid] = mid){
                        si = mid+1;
                    }
                    else{
                        ei = mid-1;
                    }
                }

            
            }

            cout<<ans<<endl;
            continue;

        }
    }

    return 0;
}