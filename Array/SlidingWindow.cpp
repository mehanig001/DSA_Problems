//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //return max sum of k consecutive element in the array
    vector<ll> v = {1,8,30,-5,20,7};
    int n = 6; int k = 3;

    // firstly precalculate sum of first k elements 
    ll sum = 0;
    for(int i = 0; i <k; i++)sum += v[i];

    ll maxi = sum;
    for(int i = k; i < n; i++){
        sum = sum-v[i-k] + v[i];  //starting wala hatate jao naya jodte hao
        maxi = max(sum,maxi);
    }

    cout<<maxi<<endl;
    return 0;
}