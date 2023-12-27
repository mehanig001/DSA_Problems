//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

// void countSort(vector<ll> &v, ll k){

//     // NAIVE AS(O(k)) TC(O(N+K))  CAN NOT USE FOR GENERAL PURPOSE OBJECTS 
//     vector<ll> temp(k,0); //will store count of low to high from 0 to k-1


//     for(ll i = 0; i < v.size(); i++){
//         temp[v[i]]++;
//     }

//     ll itr = 0;
    
//     for(ll i = 0; i < temp.size(); i++){
//         while(temp[i]>0){
//             v[itr++] = i;  //i+low if range from low to high
//             temp[i]--;

//         }
//     }


// }

void countSort(vector<ll> &v, ll k){
    //range is 0 to k-1

    //this time we will maintain three arrays

    //first orignal one

    //second as prefix sum of count items
    vector<ll> count(k,0);

    for(ll i = 0; i < v.size(); i++){
        count[v[i]]++;
    }

    vector<ll> pref(k);
    pref[0] = count[0];

    for(ll i = 1; i < k; i++){
        pref[i] = pref[i-1] + count[i];
    }

    //raaj ki baat pref se pata chal raha hai ki usse baraabar ya chote kitne elements



    //third an output array which will be sorted taking 1st and 2nd as reference
    vector<ll> output(v.size());

    for(ll i = v.size()-1; i >= 0; i--){
        //This will make this algo stable


        //we will put the ith item of v in its right place in output and decrease the count by 1
        
        //to know right position it will be count of this element -1

        output[pref[v[i]] - 1] = v[i];
        pref[v[i]]--;

    }

    for(ll i = 0; i < v.size(); i++){
        v[i] = output[i];
    }
}

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

        // if elements in v are in small rage lets say k 

        countSort(v,k);

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}