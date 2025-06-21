//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[5] = {-2,-1,-3,-5,4};

    //return idx of second largest if exist else -1

    ll max1 = LLONG_MIN;
    ll max2 = LLONG_MIN;

    for(int i = 0; i < 5; i++){
        if(arr[i] > max1){
            max2 = max1;
            max1 = arr[i];
        }
        //REMEMBER THIS CONDITION
        else if(arr[i] < max2){
            if(max2 == LLONG_MIN || max2 < arr[i]) max2 = arr[i];
        }
    }

    cout<<max2<<endl;

    return 0;
}