//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

double median(vector<ll> &v, vector<ll> &v2, ll n){
    vector<ll> vfinal(2*n);
    ll k = 0;

    ll i = 0;
    ll j = 0;

    while(i<n && j<n){
        if(v[i]<v2[j]){
            vfinal[k++] = v[i++];
        }
        else{
            vfinal[k++] = v2[j++];
        }
    }
    while(i<n){
        vfinal[k++] = v[i++];
    }
    while(j<n){
        vfinal[k++] = v2[j++];
    }
    for(auto val: vfinal)cout<<val<<" ";cout<<endl;
    double ans = (vfinal[n-1] + vfinal[n])/2.0;

    return ans;
}

//More Optimized O(log(smaller_size))
double median2(vector<ll> &v, vector<ll> &v2){
    //here both size are equal but let v.size()<=v2.size() passed always
    //applying bin search in v so that we can get a condition where all left set elements are smaller than particular element and all right elements are greater
    //we will divide elements in2 sets so that left set and right set contains equal element

    //if i in v then j = (n1+n2+1)/2-i in v2

    //we will take help of i-1,i,j-1,j elements to reach the condition
    //min in right side of v = i    min1
    //max in left side of v = i-1   max1

    //min in right side of v2 = j; min2
    //max in left side of v2 = j-1 max2

    ll n1 = v.size();
    ll n2 = v2.size();

    //applying binsearch in v1

    ll si = 0;
    ll ei = n1; //n1 not n1-1 
    ll i = si+(ei-si)/2;
   

    while(si<=ei){
        i = si+(ei-si)/2; //let i be mid always in v
        
        ll j = (n1+n2+1)/2-i; //so that no of elements in left are equal to right

        ll min1 = (i == n1)?INT_MAX*1LL : v[i];
        ll max1 = (i == 0)?INT_MIN*1LL : v[i-1];
        ll min2 = (j == n2)?INT_MAX*1LL : v2[j];
        ll max2 = (j == 0)?INT_MIN*1LL : v2[j-1];

        if(max1 <= min2 && max2 <= min1){
            if((n1+n2)%2 == 0){
                return double((max(max1,max2)+min(min1,min2))/2.0);
            }
            else{
                return double(max(max1,max2));

            }
        }
        else if(max1 > min2){
            ei = i-1;
        }
        else{
            si = i+1;
        }

    }
    

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    
    while(t--){
        ll n1,n2;
        cin>>n1>>n2;
        vector<ll> v(n1);
    
        for(ll i = 0; i < n1; i++){
            cin>>v[i];
        }
        vector<ll> v2(n2);
    
        for(ll i = 0; i < n2; i++){
            cin>>v2[i];
        }

        cout<<median2(v,v2)<<endl;
    
         
    
    }

    return 0;
}