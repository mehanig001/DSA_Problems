//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void print(ll &x, ll &y){
    if(x != y){
        cout<<x<<" ";
        y = x;
    }
}

void unionOfSortedArrays(vector<ll> &v1, vector<ll> &v2){

    ll i = 0; //itr for v1
    ll j = 0; //itr for v2

    ll prev = -1;

    while(i < v1.size() && j < v2.size()){

        //To Avoid Prev and Acc To DRY 
        /*
        BETTER TO USE

        if(i>0 && v1[i] == v1[i-1])i++;
        if(j>0 && v2[j] == v2[j-1])j++;

        then three condn >,< and = 

        then if remaining elements in any of arr left with above codn of repititon
        */

        if(v1[i] < v2[j]){
            // if(v1[i] != prev){
            //     cout<<v1[i]<<" ";
            //     prev = v1[i];
            // }
            print(v1[i],prev);
            i++;
        }

        else if(v1[i] > v2[j]){
            // if(v2[j] != prev){
            //     cout<<v2[j]<<" ";
            //     prev = v2[j];
            // }
            print(v2[j],prev);
            j++;
        }

        else{
            // if(v1[i] != prev){
            //     cout<<v1[i]<<" ";
            //     prev = v1[i];
            // }
            print(v1[i],prev);

                i++;
                j++;
            
        }
    }

    while(i < v1.size()){
        // if(v1[i] != prev){
        //         cout<<v1[i]<<" ";
        //         prev = v1[i];
        //     }
            print(v1[i],prev);

            i++;
    }
    while(j < v2.size()){
        // if(v2[j] != prev){
        //         cout<<v2[j]<<" ";
        //         prev = v2[j];
        //     }
            print(v2[j],prev);

            j++;
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> v1(n);
        vector<ll> v2(m);
    
        for(ll i = 0; i < n; i++){
            cin>>v1[i];
        }
        for(ll i = 0; i < m; i++){
            cin>>v2[i];
        }
    
        unionOfSortedArrays(v1,v2); 
    
    }

    return 0;
}