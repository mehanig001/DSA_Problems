//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

bool isPresent(string &str, string &s2, ll n, ll n2){

    if(n2 == 0){
        return true;
    }
    if(n == 0){
        return false;
    }

    if(str[n-1] == s2[n2-1]){
        return isPresent(str,s2,n-1,n2-1);
    }
    else{
        return isPresent(str,s2,n-1,n2);

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n,n2;
        cin>>n>>n2;

        string str,s2;
        cin>>str>>s2;

        

        //Iterative
        bool ans = 0;
        

        ll i = 0, j = 0;

        // while(i < n && j < n2){
        //     if(str[i] == s2[j]){
        //         i++;
        //         j++;

        //     }
        //     else{
        //         i++;
        //     }
        // }
        // if(j == n2){
        //     ans = 1;
        // }
      

        //Recursive
        ans = isPresent(str,s2,n,n2);

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
12 4
gautammehani
gahi
12 5
gautammehani
tgmeh
12 3
gautammehani
taa
12 6
gautammehani
gtmhai




O/P
YES
NO
YES
YES


*/