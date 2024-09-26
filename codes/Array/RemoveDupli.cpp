//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {10,10,20,20,20,30,30,30}; //Sorted
    int n = 8;
    // for(int i = 0; i < arr.size()-1; i++){ //size is changing bruh
    //     if(arr[i] == arr[i+1]){
    //         arr.erase(arr.begin()+i+1,arr.begin()+i+2);
    //         i--; //kyuki ab age wala element ek index peeche shift ho chuka hai bhai
    //     }
    // }

    //More Optimized
    int ctr = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[ctr-1]){
            arr[ctr] = arr[i];
            ctr++;
        }
    }
    //unique ko pahle hi ek sath kar diya ek hi bar me aur size chaihiye to ctr hai hi
    cout<<ctr<<endl;

    //shuru ke teen hi hai 
    for(auto val : arr)cout<<val<<" ";cout<<endl;

    return 0;
}