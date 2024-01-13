//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


// TC O((n-m+1)*m)
void searchPattern(string str,string pattern, ll n, ll m){
    ll j = 0;
    bool found = 0;

    for(ll i = 0; i < n; i++){
        if(str[i] == pattern[j]){
            j++; 
            if(j == m){
                found = 1;
                cout<<i-m+1<<" ";
                i = i-m+1; //if all characters are distinct in pattern remove this line for TC O(N)
                j = 0;
                
            }
        }
        else{
            j = 0;
        }
    }
    if(!found){
        cout<<"NOT FOUND";
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        string str;
        cin>>str;

        string pattern;
        cin>>pattern;

        searchPattern(str,pattern,n,m);
        
         
    
    }

    return 0;
}

/*
I/P
3
18 3
keetabikeedakeekee kee
5 3
aaaaa aaa
6 2
gautam gaut


O/P
0 7 12 15 
0 1 2 
0
*/