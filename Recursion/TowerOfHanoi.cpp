//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

//print statement same hoga base case me bhi aur rec call k beech m bhi
//rec call aise lagegi ki n-1 ko left se middle bhej do right ki maddad se fir print k bad middle se right bhej do
//total moves pow(2,n) - 1;

void towerOfHanoi(int n, char src, char hlp, char dest){
    if(n == 1){
        cout<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1,src,dest,hlp);
    cout<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,hlp,src,dest);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    towerOfHanoi(2,'A','B','C');

    return 0;
}