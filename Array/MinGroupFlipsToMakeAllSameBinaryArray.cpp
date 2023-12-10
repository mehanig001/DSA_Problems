//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {0,1,1,0,1,0,1,1};

    //Catch is here only possibility is groups count will differ by atmost 1

    for(int i = 1; i < v.size(); i++){
        while(v[i] == v[0] && i < v.size()) i++;
        cout<<i<<" ";
        while(v[i] != v[0] && i < v.size())i++;
        cout<<i-1<<endl;
    }

    return 0;
}