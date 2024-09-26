//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

bool isPalindrome(string str, ll si, ll ei){
    if(si>=ei){
        return true;
    }
    if(str[si] != str[ei]){
        return false;
    }

    return isPalindrome(str,si+1,ei-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        string str;
        cin>>str;

        ll si = 0, ei = n-1;

        //Iterative
        bool ans = 1;
        while(si < ei){
            if(str[si] != str[ei]){
                ans = 0;
                break;
            }
            si++;
            ei--;
        }

      

        //Recursive
        // ans = isPalindrome(str,si,ei);

        if(ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
         
    
    }

    return 0;
}


/*
I/P
4
7
racecar
3
bob
6
gautam
6
mehani



O/P
YES
YES
NO
NO


*/