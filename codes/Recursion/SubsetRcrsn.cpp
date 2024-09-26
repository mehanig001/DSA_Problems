//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 
void subset(string str,string newstr = "",int i = 0){

    if(i == str.size()){
        cout<<newstr<<endl;
        return;
    }


    subset(str,newstr,i+1);
    subset(str,newstr+str[i],i+1);


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "abc";

    subset(str);

    return 0;
}