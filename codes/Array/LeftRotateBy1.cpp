//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[5] = {1,2,3,4,5};

    // int first = arr[0];
    // for(int i = 1; i < 5; i++){
    //     arr[i-1] = arr[i];
    // }
    // arr[5-1] = first;

    //agar k elements ko karna hota to aisa kaam nhi chlta
    //1 ka new index = (0 -1+n)%n
    //2 ka new index = (1 -1+n)%n
    //
    //n-1 ka new index = (n-1 -1+n)%n

    //let k = 4 to O/P 5 1 2 3 4
    int k = 2;
    int newarr[5];
    int n = 5;
    for(int i = 0; i < 5; i++){
        newarr[(i-k+5)%5] = arr[i];

    }
    for(auto val: newarr)cout<<val<<" ";cout<<endl;


    return 0;
}