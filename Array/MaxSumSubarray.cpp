//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[] = {2,3,-8,7,-1,2,3};
    int n = 7;

    //O(nsq)for every subset calc sum and max will ans

    //O(n) chk max possible with curr element and prev maxsum only

    int maxsum[n];
    maxsum[0] = v[0];

    for(int i = 1; i < n; i++){
        maxsum[i] = max(maxsum[i-1]+v[i],v[i]);
        //peeche neg hua to nhi lega nhi to le lega 
    }

    cout<<*max_element(maxsum,maxsum+n)<<endl;

    // 2,3,-8,7,-1,2,3
    // 2,5,-3,7,6,8,11

    //7 ne -3 lene se mana kr diya bhaiyaa kyuki sum ghata raha tha wo
    

    //ans = 11

    //with AS O(1)
    int x = v[0];
    int ans = v[0];
    for(int i = 1; i < n; i++){
        x = max(v[i],x+v[i]);
        ans = max(ans,x);
    }
    cout<<ans<<endl;

    return 0;
}