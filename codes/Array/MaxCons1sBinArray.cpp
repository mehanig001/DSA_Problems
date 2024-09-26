//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[] = {0,1,0,0,1,0,1,1,1,0,0,1,1,1,1};
    int n = sizeof(v)/sizeof(int);

    int maxi = 0;
    for(int i = 0; i < n; i++){
        int ct = 0;

        while(v[i] == 1){
            i++;
            ct++;
        }
        maxi = max(ct,maxi);
    }
    cout<<maxi<<endl;

    return 0;
}