//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int maxSubarrSum(vector<int> &v, int n){
    int maxsum = v[0];
    int currsum = v[0];
    for(int i = 1; i < n; i++){
        currsum = max(currsum+v[i],v[i]);
        maxsum = max(maxsum,currsum);
    }

    return maxsum;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    vector<int> v = {3,-4,5,6,-8,7};
    int n = 6;
    int normalmax = maxSubarrSum(v,n); 

    //ans will be max of normal subarrays maxsum and maxsum that can be obtained through circular arr
    int sum = accumulate(v.begin(), v.end(), 0);

    
    for(int i = 0; i < n; i++){ 
        v[i] = -1*v[i];
    }

    int circularmax = sum + maxSubarrSum(v,n);  //+ isliye kuki hamne aisa sub hata diya jo total sum ko kam kar raha tha

    int ans = max(normalmax,circularmax);


    if(*max_element(v.begin(),v.end())<0){
        ans = normalmax;
    }
    cout<<ans<<endl;


    return 0;
}