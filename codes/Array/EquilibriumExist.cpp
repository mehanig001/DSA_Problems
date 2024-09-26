//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //equi means leftsum = rightsum for any element
    vector<int> v = {3,4,8,-9,9,7};
    int n = 6;

    int sum = accumulate(v.begin(), v.end(),0);

    int leftsum = 0;
    int rightsum = sum - v[0];

    for(int i = 1; i < n; i++){
        if(leftsum == rightsum){
            cout<<"YES";
            break;
        }
        leftsum += v[i-1];
        rightsum-=v[i];

        cout<<leftsum<<" "<<rightsum<<endl;

        //can be also done by using prefsum and suffix sum
        
    }


    return 0;
}