//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


void cycleSortRepeated(vector<ll> &v){

    //will complete it later
    ll n = v.size();
    for(ll cs = 0; cs < n-1; cs++){
        ll pos = cs;
        ll item = v[cs];

        for(ll i = cs+1; i < n; i++){
            if(v[i]<item)pos++;      
        }
        swap(v[pos],item);

        while(cs != pos){
            pos = cs;
            for(ll i = cs+1; i < n; i++){
                if(v[i]<item)pos++;      
            }
            swap(v[pos],item);
            }

    }
}


void cycleSortDistinct(vector<ll> &v){

    //choose items until not repeated

    //then fix all items in their right places  

    ll count = 0; //to count min no of swaps required to sort an array
    
    for(ll cs = 0; cs < v.size()-1; cs++){
        //cs means cycle start 
        ll pos = cs;
        ll item = v[cs];

        for(ll i = cs+1; i < v.size(); i++){
            if(v[i] < item){ //counting number of lesser items in right to have correct position of the item
                pos++;
            }
        }
        swap(item,v[pos]); //swapped item to its correct posn and taken other from that posn in item
       

        if(cs != pos)count++;

        //process new items until cycle forms
        while(pos != cs){
            pos = cs;
            for(ll i = cs+1; i < v.size(); i++){
                if(v[i] < item){
                    pos++;
                }
            }
            swap(item,v[pos]);
        
        if(cs != pos)count++;


        }

        //one cycle items are fixed to their correct position then cs will incremented and check for next cycle
    }   

    cout<<"In "<<count<<" swaps"<<endl;
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
    
        // cycleSortDistinct(v);
        cycleSortRepeated(v);


        for(auto val: v){
            cout<<val<<" ";
        }
        cout<<endl;
        
          
    
    }

    return 0;
}

/*
3
4
4 3 2 1
4
1 2 3 4 
5
1 4 2 5 3

O/P
1 2 3 4 
1 2 3 4 
1 2 3 4 5

*/