//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[] = {2,4,14,6,8};
    int n = 5;

    int maxi = 1;

    for(int i = 1; i < n; i++){
        int ct = 1;
        bool bothodd = (v[i]&1)&&(v[i-1]&1);
        bool botheven = (!(v[i]&1))&&(!(v[i-1]&1));
        while(!(bothodd || botheven) && i < n){
            ct++;
            i++;
        }
        maxi = max(ct,maxi);
    }

    cout<<maxi<<endl;

    return 0;
}