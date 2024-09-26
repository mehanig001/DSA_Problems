//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


//Recursive
ll binarySearch(vector<ll> &v, ll si, ll ei, ll key){
    if(si > ei){
        return -1;
    }
    ll mid = si + (ei-si)/2;
    if(v[mid] == key){
        return mid;
    }
    else if(v[mid]>key){
        ei = mid-1;
        binarySearch(v,si,mid-1,key);
    }
    else{
        si = mid+1;
        binarySearch(v,mid+1,ei,key);
    }
}

//Iterative
ll binarySearch(vector<ll> &v, ll key){
   
    ll si = 0, ei = v.size()-1;
    ll mid = si + (ei-si)/2;
    ll ans = -1;

    while(si<=ei){
        mid = si+(ei-si)/2;
        
        if(v[mid] == key){
            ans = mid;
            break;
        }
        else if(v[mid]>key){
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }



    return ans;
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
        //Sorted
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }

        cout<<binarySearch(v,0,v.size()-1,k)<<" ";
        cout<<binarySearch(v,k)<<endl;

        /*
I/P
6
5 1
1 7 8 9 12
5 10
1 4 6 7 19
10 9
1 2 3 4 5 6 8 9 10 11 
3 4
1 4 8 
4 8
1 5 7 8
7 9
1 2 4 5 6 8 9 


O/P
0 0
-1 -1
7 7
1 1
3 3
6 6

        */
    
    }

    return 0;
}