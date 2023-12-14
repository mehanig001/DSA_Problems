//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

//If que is like count no of occurance of element in a sorted array ans will be
// lastocc - firstocc + 1
// if element is present in arr o/w 0


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

    ll si = 0, ei = v.size()-1;
    ll mid = si + (ei-si)/2;
    ll ans = -1;

    while(si <= ei){
        mid = si+(ei-si)/2;
        
        if(v[mid] == k){
            // while(v[mid] == k && mid >= 0)mid--;
            // ans = mid+1;
            
            //optimized
            if(mid == 0 || v[mid-1] != k ){ //last v[mid+1] != k OR mid+1==n
                ans = mid;
                break;
            }
            else{
                ei = mid-1;  //last occ si = mid+1
            }
        }
        else if(v[mid]>k){
            ei = mid-1;
        }
        else{
            si = mid+1;
        }
    }
         
    cout<<ans<<endl;
    }

    return 0;


}

/*

I
6
5 9
1 9 9 9 12
5 10
1 4 6 7 19
10 9
1 2 3 4 5 9 9 9 9 9 
3 4
1 4 8 
7 1
1 1 4 5 6 8 9
4 8
1 5 7 8 


O/P
1
-1
5
1
0
3

*/