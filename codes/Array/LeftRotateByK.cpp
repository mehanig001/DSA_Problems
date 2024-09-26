//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //O(n) TC with AS = O(1) kyuki AS O(n) se to i+k %n wale formule se bhi ho jayega
    vector<int> v = {1,2,3,4,5};
    int k = 2; 
    // O/P: 3,4,5,1,2

    reverse(v.begin(),v.begin()+k); //2 1 3 4 5
    reverse(v.begin()+k,v.end());   //2 1 5 4 3
    reverse(v.begin(),v.end());     //3 4 5 1 2

    for(auto val : v)cout<<val<<" ";cout<<endl;

    return 0;
}