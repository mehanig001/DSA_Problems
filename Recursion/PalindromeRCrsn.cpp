//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

bool isPalindrome(string &str, ll si , ll ei ){

    if(si>ei) return true;

    return (str[si] == str[ei])&& (isPalindrome(str,si+1,ei-1));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "gautammatuag";
    ll n = str.size();
    cout<<isPalindrome(str,0,n-1);

    return 0;
}