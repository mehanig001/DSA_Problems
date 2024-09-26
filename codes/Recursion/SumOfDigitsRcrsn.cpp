//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


int sumOfDigit(int n){
    if(n == 0)return 0;

    return (n%10) + sumOfDigit(n/10);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x = 5821;
    cout<<sumOfDigit(x);

    return 0;
}