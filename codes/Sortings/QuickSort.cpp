//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

// ll partition(vector<ll> &v, ll si, ll ei){
//     ll pivot = v[ei];

//     ll i = si-1;
    
//     for(ll j = si; j <= ei; j++){
//         if(v[j]<pivot){
//             i++;
//             swap(v[i],v[j]);
//         }
//     }
//     swap(v[i+1],v[ei]);
//     return i+1;
// }

ll partition(vector<ll> &v, ll si, ll ei){
    //Hoare's

    ll pivot = v[si];

    ll i = si-1;
    ll j = ei+1;
    while(true){

    
    do{
        i++;
    }while(v[i]<pivot);
    do{
        j--;
    }while(v[j]>pivot);


    if(i>=j)return j;

    swap(v[i],v[j]);
    
    }
}

void qSort(vector<ll> &v, ll si, ll ei){
    if(si>=ei){
        return;
    }
    ll p = partition(v,si,ei);
    // qSort(v,si,p-1);
    qSort(v,si,p);
    qSort(v,p+1,ei);
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
    
        qSort(v,0,v.size()-1); 

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
         
    
    }

    return 0;
}