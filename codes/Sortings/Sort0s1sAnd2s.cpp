//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void sort(vector<ll> &v){
    //using hoare's mehod we have to sort 0s and 1s using a mid

    //0 to si-1 for 0s
    //si to mid-1 for 1s
    //and mid+1 to rest unknown

    ll i = 0, mid = 0, ei = v.size()-1;
        
    while(mid<=ei){
         
        if(v[mid] == 0){
            swap(v[i],v[mid]);
            mid++;
            i++;
        }
        else if(v[mid] == 1){
            mid++;
        }
        else{
            swap(v[mid], v[ei]);
            ei--;
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
        vector<ll> v(n);
    
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }

        sort(v);
    
        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}