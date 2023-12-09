//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[] = {1,5,3,8,12};
    int n = 6;

    int leftmin = v[0];
    int profit = 0;
    for(int i = 1; i < n; i++){

        if(v[i]<v[i-1]){
            //Drop
            profit += v[i-1] - leftmin;
            leftmin = v[i];
        }
    }
    if(v[n-1] - leftmin > 0)
    profit += v[n-1] - leftmin;


    //Simple approach is that if(v[i]-v[i-1] > 0)add in profit else do nothing (graph badh raha ho to profit)

    cout<<profit<<endl;

    return 0;
}