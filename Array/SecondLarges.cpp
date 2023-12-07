//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[5] = {2,1,3,5,4};

    //return idx of second largest if exist else -1

    int max1 = 0;
    int max2 = -1;

    for(int i = 0; i < 5; i++){
        if(arr[i] > arr[max1]){
            max2 = max1;
            max1 = i;
        }
        //REMEMBER THIS CONDITION
        else if(arr[i]<arr[max1] ){
            if(max2 == -1 || arr[max2] < arr[i]) max2 = i;
        }
    }

    cout<<max2;

    return 0;
}