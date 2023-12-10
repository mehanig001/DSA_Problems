//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> left = {1,2,4};
    vector<int> right = {4,5,7};

    //condn is l<r<100

    vector<int> freq(100,0);


    //O(N*MAX)
    for(int i = 0; i < left.size(); i++){

        for(int j = left[i]; j <= right[i];j++){
            freq[j]++;
        }
    }
    ll maxi = *max_element(freq.begin(), freq.end());
    for(int i = 0; i < freq.size(); i++){
        if(freq[i] == maxi){
            cout<<i<<endl;
        }
    }

    for(auto val: freq){
        cout<<val<<" ";
    }
    cout<<endl;

    //O(N + MAX)
    //using prefsum

    //for every itr we make freq[left] as 1 and freq[right +1] as -1

    for(int i = 0; i < left.size(); i++){
        freq[left[i]] = 1;
        freq[right[i]+1] = -1;
    }
    //now prefix sum me jiska sabse bada hoga whi ans
    for(auto val: freq){
        cout<<val<<" ";
    }
    cout<<endl;
    
     
    for(int i = 1; i < freq.size(); i++){
        freq[i] = freq[i-1] + freq[i];
    }
    ll max = *max_element(freq.begin(), freq.end());
    
    for(int i = 0; i < freq.size(); i++){
        if(freq[i] == max)cout<<i<<endl;
    }


    return 0;
}