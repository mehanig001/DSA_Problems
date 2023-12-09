//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
    vector<int> v = {2,3,10,6,4,8,1};

    int leftmin = v[0];
    // int rightmax = v[1];
    // int maxd = rightmax - leftmin;
    int maxd = v[1]-v[0];

    for(int i = 1; i < v.size(); i++){
        leftmin = min(leftmin,v[i-1]);
        // if(leftmin == v[i-1])rightmax = v[i];

        // else rightmax = max(v[i],rightmax);

        // maxd = max(maxd,rightmax-leftmin);
        maxd = max(maxd,v[i]-leftmin);
    }

    cout<<maxd<<endl;




    return 0;
}