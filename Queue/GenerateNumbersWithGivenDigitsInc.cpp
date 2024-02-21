//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    //let given digits be 5,6  ans: 5  6  56  66  65  66  556  566  656  666

    queue<string> q;
    q.push("5");
    q.push("6");

    int n = 10; //10 terms

    while(n--){
        string tp = q.front();
        cout<<tp<<" ";
        q.pop();
        q.push(tp + "5");
        q.push(tp + "6");

    }

    return 0;
}

/*
O/P
    
5 6 55 56 65 66 555 556 565 566

*/