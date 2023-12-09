//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v[] = {4,2,0,6,3,2,5};
    int  n = 7;

    int totalWater = 0;


    //O(Nsq)
    for(int i = 0; i < n; i++){
        int leftmax = v[i],rightmax = v[i];

        for(int j = 0; j <i; j++){
            if(v[j]>leftmax){
                leftmax = v[j];
            }
        }
        for(int j = n-1; j >i; j--){
            if(v[j]>rightmax){
                rightmax = v[j];
            }
        }

        totalWater += min(leftmax,rightmax) - v[i];

    }

    cout<<totalWater<<endl;


    //O(N) precalculate leftmax and rightmax for each index and store in another arrays

    int leftmax[n];
    int rightmax[n];

    leftmax[0] = v[0];
    rightmax[n-1] = v[n-1];
    for(int i = 1; i < n; i++){
        leftmax[i] = max(leftmax[i-1],v[i]);
    }
    for(int i = n-2; i>=0; i--){
        rightmax[i] = max(rightmax[i+1], v[i]);
    }

    //calc
    totalWater = 0;

    for(int i = 0; i < n; i++){
        totalWater += min(leftmax[i],rightmax[i]) - v[i];

    }
    cout<<totalWater<<endl;
        
   return 0;
}


//Har ek index pr lftmax aur rightmax ka prabhaav hai isliye calc to krna pdege phle hi calc krke rkh do
