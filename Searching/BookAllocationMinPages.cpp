//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

bool isPossible(vector<ll> v, ll mid, ll k){
    ll stud = 0;

    for(ll i = 0; i < v.size(); i++){
        ll currsum = 0;
        ll init = i;
        if(currsum + v[i] > mid)stud++;
        while(currsum + v[i] <= mid && i < v.size()){
            currsum += v[i];
            i++;
        }
            // cout<<"currsum: "<<currsum<<endl;
        stud++;
        if(i != init)i--;
    }
    if(stud <= k)return true;


    return false;

}

//Instead of using while loop 
//simply we can update no of std when currsum > mid
//otherwise we will add currsum with v[i]
//using if else conditions

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        ll sum = accumulate(v.begin(), v.end(), 0);

        ll si = 0;
        ll ei = sum;

        ll mid,ans = 0;

        while(si <= ei){
            mid = si + (ei - si)/2;
            // cout<<mid<<endl;
            if(isPossible(v,mid,k)){
                ans = mid;
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }
        cout<<ans<<endl;
    
    }

    return 0;
}

/*
IP
3
8 3
10 5 30 1 2 5 10 10
4 2
10 20 30 40
3 1
10 20 30


OP
30
60
60
*/