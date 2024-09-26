//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int waysToCutRope(int n, int a, int b, int c){

    if(n == 0)return 0;
    if(n<0)return -1;
   
    ll res = max(max(waysToCutRope(n-a,a,b,c),waysToCutRope(n-b,a,b,c)),waysToCutRope(n-c,a,b,c));
    if(res == -1)return -1; //teeno hi cuts invalid hai
    return 1+res;
   

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,a,b,c;
    cin>>n>>a>>b>>c;

    cout<<waysToCutRope(n,a,b,c);

    return 0;
}