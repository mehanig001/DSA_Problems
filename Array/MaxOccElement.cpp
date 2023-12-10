//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v = {0,8,8,8,48,80,8};//max occ will occur strictly more than n/2 times = 8
    //return any of the index of max occuring element 0,3,4,5 int this case

    //Step 1
    // assume v[0] is maxocc and ct = 1;

    int idx = 0;
    int ct = 1;

    for(int i = 1; i < v.size(); i++){
        if(v[i] == v[idx])ct++;
        else{
            ct--;
        if(ct == 0){
            ct = 1;
            idx = i;
        }
        }
    }

    //Step to idx returned by step 1 is of max occ element or not
    int ctr = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[idx] == v[i])ctr++;
    }

    if(ctr>v.size()/2){
        cout<<idx<<endl;
    }
    else{
        cout<<"NO MAX OCCURING ELEMENT FOUND"<<endl;
    }


    return 0;
}