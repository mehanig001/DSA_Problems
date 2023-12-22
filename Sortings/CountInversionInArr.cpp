//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll mergeCountInversion(vector<ll> &v, ll si, ll mid, ll ei){

    ll i = si;
    ll j = mid+1;

    vector<ll> temp(ei-si+1);
    ll k = 0;

    ll ans = 0;

    while(i<=mid && j<=ei){
        if(v[i]<=v[j]){
            //no problem
            temp[k++] = v[i++];
        }
        else{
            //3rd case
            temp[k++] = v[j++];
            ans = ans + mid-si+1 - (i-1);
            //right wala ith wale se chota hai to uske age walo se bhi chota hoga 
        }
    }
    while(i<=mid){
        temp[k++] = v[i++];
        
    }
    while(j<=ei){
        temp[k++] = v[j++];
        
    }

    for(ll i = si,k = 0; k < ei-si+1; i++,k++){
        v[i] = temp[k];
    }

    return ans;
}

ll countInversion(vector<ll> &v, ll si, ll ei){
    //Naive O(nsq)

    //O(nlogn using concept of merge sort)

    ll ans = 0;

    //for an inverted pair x>y 
    //3 cases 

    //1st both x and y lies in left half si to mid
    //2nd both x and y lies in right half mid+1 to ei
    //3rd x lies in left half and y in right half

    if(si>=ei){
        return ans;
    }
    ll mid = si + (ei-si)/2;

    ans += countInversion(v,si,mid);
    ans += countInversion(v,mid+1,ei);
    ans += mergeCountInversion(v,si,mid,ei);

}

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
    
        cout<<countInversion(v,0,n-1)<<endl; 

    
    }

    return 0;
}