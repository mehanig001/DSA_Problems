//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

ll findRepeatition(vector<ll> v, ll n){

    ll slow = v[0],fast = v[0];

    do{
        slow = v[slow];
        fast = v[v[fast]];
    }while(slow != fast);

    //loop detected and slow and fast meet at some point inside loop fast has travelled k distance more than slow

    slow = v[0]; //to find starting point of loop

    while(slow != fast){
        slow = v[slow];
        fast = v[fast]; //with same speed

    }

    return slow;
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

        //O(N) 
        //My Approach

        /*
        ll maxi = *max_element(v.begin(), v.end());
        ll arrsum = accumulate(v.begin(), v.end(),0);
        ll sum2 = (maxi*(maxi+1))/2;

        ll mini = *min_element(v.begin(), v.end());

        ll ctr;

        if(mini == 0){
            ctr = n-maxi-1;
        }
        else{
            ctr = n-maxi;
        }

        ll diff = arrsum - sum2;

        ll ans = diff/ctr;

        cout<<ans<<endl;
        */

       

       //MASTERS APPROACH CYCLE METHOD
       // starting from 1 if starting from 0 add 1 before checking and return ans--

       cout<<findRepeatition(v,n)<<endl;

         
    
    }

    return 0;
}