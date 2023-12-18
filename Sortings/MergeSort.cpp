//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void merge(vector<ll> &v, ll si, ll mid, ll ei){
  
    vector<ll> temp(ei-si+1);
    ll k = 0;

    ll i = si;
    ll j = mid+1;

    while(i <= mid && j <= ei){
        if(v[i]<v[j]){
            temp[k++] = v[i++];
        }
        else{
            temp[k++] = v[j++];
        }
    }
    while(i <= mid){
      
            temp[k++] = v[i++];
      
    }
    while( j <= ei){
     
            temp[k++] = v[j++];
        
    }

    for(ll i = si,k = 0; k < ei-si+1; i++,k++){
        v[i] = temp[k];
    }

    return;
}

void mergeSort(vector<ll> &v, ll si, ll ei){

    if(si>=ei){
        return;
    }
    ll mid = si+(ei-si)/2;

    mergeSort(v,si,mid);
    mergeSort(v,mid+1,ei);

    merge(v,si,mid,ei);

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
    
        mergeSort(v,0,n-1);

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}