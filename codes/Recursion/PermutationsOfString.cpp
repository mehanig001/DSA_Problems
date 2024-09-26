//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

void permute(string str,int i = 0){
    if(i == str.size()-1){
        cout<<str<<endl;
        return;
        }
    for(int j = i; j < str.size(); j++){
        swap(str[i],str[j]);
        permute(str,i+1);
        swap(str[j],str[i]);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "abc";

    permute(str);

    return 0;
}