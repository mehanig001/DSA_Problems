//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {2,3,5,4,6,1};
    int n = 6;

    //weighted sum means 1*arr[l] + 2*arr[l+1] + 3*arr[l+2] + ............... + (r-l+1)arr[r]

    vector<int> normalpref(n);
    vector<int> weightedpref(n);
    normalpref[0] = weightedpref[0] = v[0];
    for(int i = 1; i < n; i++){
        normalpref[i] = normalpref[i-1] + v[i];
        weightedpref[i] = weightedpref[i-1] + (i+1)*v[i];
    }

    for(auto val: normalpref){
        cout<<val<<" ";
    }
    cout<<endl;
    
    for(auto val: weightedpref){
        cout<<val<<" ";
    }
    cout<<endl;
    
      

    int l = 2, r = 3;  //we want 1*5 + 2*4 = 13
    // if(l == 0)then dont substract
    int ans = (weightedpref[r] - weightedpref[l-1]) - (l)*(normalpref[r] - normalpref[l-1]);

    cout<<ans<<endl;

    return 0;
}