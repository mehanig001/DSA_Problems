//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {7,10,4,3,6,5,2};
    int n = 7;

    vector<int> ans;
    //Right me use bad koi na ho 
    //O/P: 10 6 5 2
    int max = v[n-1];
    ans.push_back(max);
    for(int i = n-2; i >=0; i--){
        if(v[i] > max){
            ans.push_back(v[i]);
            max = v[i];
        }
    }

    reverse(ans.begin(), ans.end());

    for(auto val : ans){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}