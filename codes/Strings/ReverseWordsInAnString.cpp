//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        // ll n;
        // cin>>n;
        string str = "I am Gautam Mehani";


        string fw = "";
        ll i = 0;
        while(str[i] != ' ' && i < str.size()){
            fw+=str[i];
            i++;
        }
        
        // getline(cin,str);

        reverse(str.begin(), str.end());

        string word = "";
        for(ll i = 0; i < str.size(); i++){
            if(str[i] != ' ' ){
                word+=str[i];
            }
            else{
                reverse(word.begin(), word.end());
                cout<<word<<" ";
                word = "";
            }
        }
        cout<<fw<<endl;
         
    
    }

    return 0;
}

/*

O/P
Mehani Gautam am I
*/