//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void heapify(vector<ll> &v,ll n,ll i){
    // {1,2,3,4,5}
    

    ll left = i*2+1;
    ll right = i*2+2;

    ll largest = i;

    if(left < n){
        if(v[left]>v[i])largest = left;
    }
    if(right < n){
        if(v[right] > v[largest])largest = right;
    }

   
    if(largest != i){
        swap(v[largest],v[i]);
        heapify(v,n,largest);
    }



    
}

void buildMaxHeap(vector<ll> &v){
//build maxheap
    ll n = v.size();

    for(ll i = (n-2)/2; i>=0; i--){
        heapify(v,n,i);
    }
 
}

void heapSort(vector<ll> &v){

    
    ll n = v.size();
    buildMaxHeap(v);

    //until array is sorted 
    //reverse root and last child-> It would fix last element to the next largest

    ll last = n-1;
    while(last>0){
        swap(v[0],v[last]);
        heapify(v,last,0);
        last--;
    }

    //heapify



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
    
        heapSort(v);

        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}