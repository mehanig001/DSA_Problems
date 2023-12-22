//<-----------------------------SSDN------------------------------>

#include<bits/stdc++.h>
#define ll long long
using namespace std; 


//sort arr and return v[k-1] in O(nlogn) o/w

ll partition(vector<ll> &v, ll si, ll ei){
    //take last element as pivot;
    ll pivot = v[ei];
    ll i = si-1;; //window of smaller elements
    ll j = ei+1;

    for(ll j = si; j < ei; j++){
        if(v[j] < pivot){
            i++; //inc window size by 1 to insert smaller element found in window
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[ei]);

    return i+1;//currrent position for pivot
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

        //using lumoto partition algo we can save time

        //idea is if p return k-1 we reach to the ans 

        ll si = 0;
        ll ei = v.size()-1;
        
        while(si<ei){
        ll p = partition(v,si,ei);

            if(p == k-1){
                cout<<v[p]<<endl;
                break;
            }

            else if(p > k-1){ //p returns count of smaller elements present in array less than v[p]
                //....v[p].........

                //go in left side as count of left elements is greater than required count
                ei = p-1;

            }
            else{
                si = p+1;
            }
        }

    
        //Time And Space Complexity will be same as Quick Sort Algo but sometimes in very first opn we can get kth smallest element
    
    }

    return 0;
}

//For min diff in array sort arr and take min var to stor min diff b/w 2 consecutive elements in one go

//Chocolate Distribution Problem : Find for every k distribution minn val of (max - min) 
//again sort array and take mind as v[k-1]-v[0] now traverse and take mind

