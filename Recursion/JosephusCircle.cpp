//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 
int jos(int n, int k){
    if(n <= 1)return 0;

    return (k + jos(n-1,k))%n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    cout<<jos(n,k);

    return 0;
}