//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[6] = {8,5,0,10,0,20};
    int k = 0;
    for(int i = 0; i < 6; i++){
        if(arr[i] != 0)arr[k++] = arr[i];
    }
    for( ; k<6; k++){
        arr[k] = 0;
    }

    for(auto val : arr)cout<<val<<" ";cout<<endl;

    return 0;
}