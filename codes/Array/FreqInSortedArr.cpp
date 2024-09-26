//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {10,20,30,40};
    int n = 4;

    for(int i = 0; i < n; i++){
        int ct = 1;
        while(arr[i+1] == arr[i] && i < n-1){
            i++;
            ct++;
        }
        cout<<arr[i]<<" "<<ct<<endl;
    }

    return 0;
}