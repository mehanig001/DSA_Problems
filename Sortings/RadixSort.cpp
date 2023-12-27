//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 



//we will sort each digits from last one by one according using stable count sort algo range from 0 to 9
// TC O(d*(N+b)); b->range



void countingSort(vector<ll> &v,  ll place){

   
    vector<ll> count(10,0);

    for(ll i = 0; i < v.size(); i++){
        // count[v[i]]++;
        count[(v[i]/place)%10]++;
    }

    vector<ll> pref(10);
    pref[0] = count[0];

    for(ll i = 1; i < 10; i++){
        pref[i] = pref[i-1] + count[i];
    }

    vector<ll> output(v.size());

    for(ll i = v.size()-1; i >= 0; i--){
        // output[pref[v[i]] - 1] = v[i];
        output[pref[(v[i]/place)%10] - 1] = v[i];
        
        pref[(v[i]/place)%10]--;
    }

    for(ll i = 0; i < v.size(); i++){
        v[i] = output[i];
    }

}
void radixSort(vector<ll> &v){
    ll maxi = *(max_element(v.begin(), v.end()));

    for(ll exp = 1; (maxi/exp) > 0; exp*=10){
        countingSort(v,exp);
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
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }

        
        radixSort(v);

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
         
         
    
    }

    return 0;
}