//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++){
            cin>>arr[i];
        }
        deque<int> dq(k);

    //we will maintain first element of deque as the index of largest element of curr subarr
    //if a larger element comes all element will not remain useful 
    //if smaller comes we pushback them

        for(int i = 0; i < k; i++){
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        for(int i = k; i < n; i++){
            cout<<arr[dq.front()]<<" ";

            //rem prev windows ele 
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[i] >= arr[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        cout<<arr[dq.front()]<<endl;
        
    
    }

    return 0;
}

/*

I/P
5
8 3
1 2 3 4 5 6 7 8
8 3
8 7 6 5 4 3 2 1
4 1 
7 5 10 6
3 3
1 2 3
8 3
10 12 8 15 20 30 1 50

O/P

3 4 5 6 7 8
8 7 6 5 4 3
7 5 10 6
3
12 15 20 30 30 50

*/