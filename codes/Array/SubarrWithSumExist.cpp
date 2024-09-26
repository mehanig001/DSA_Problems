//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> v = {1,4,20,3,10,5};
    ll sum = 40, n = 6;

    ll currsum = v[0];
    ll k = 0;

    for(ll i = 1; i < n; i++){
        if(currsum == sum ){
            cout<<"YES";
            break;
        }
        else if(currsum + v[i] < sum){
            currsum += v[i];
        }

        else if(currsum + v[i] > sum){
            currsum+=v[i];
            while(currsum + v[i] > sum && k <= i){
                
            currsum -= v[k];
            // cout<<currsum<<endl;
            if(currsum == sum){
            cout<<"YES";
            return 0;
            }
            k++;
            }
        }
        if(i == n-1)cout<<"NO"<<endl;
    }



    return 0;
}