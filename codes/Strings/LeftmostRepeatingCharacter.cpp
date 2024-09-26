//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 


//Output the index of leftmost character that repeats in a given string


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        string str;
        cin>>str;

        unordered_map<char,ll> s;
        bool present = 0;
        // ll ans = n;

        // for(ll i = 0; i < n; i++){
        //     if(s.find(str[i]) != s.end()){
        //         auto f = s.find(str[i]);
        //         ans = min(f->second,ans);
        //         present = 1;
                
        //     }
        //     s.insert({str[i],i});
        // }

        // if(!present){
        //     cout<<"NO REP CHAR"<<endl;
        // }
        // else{
        //     cout<<ans<<endl;
        // }




         //without using aux space
         
         //Naive: O(Nsq) for every char chk if it is present in right side

        //Better approach
        
        int freq[26] = {0};

        for(ll i = 0; i < n; i++){
            freq[str[i]-'a']++;
        }

        for(ll i = 0; i < n; i++){
            if(freq[str[i]-'a'] > 1){
                cout<<i<<endl;
                present = 1;
                break;
            }
        }

        if(!present)cout<<-1<<endl;

    //here two traversal are req else what we can do is
    // create findex arr with -1 values and as we traverse if(curr is -1)store idx else ans = min(ans,findex[curr])

    //more optimized version traverse string from right to left and take ans = -1
    //maintain a boolean visited array for  each char if(it is visited)set ans = i;



    }

    return 0;
}

/*

4
6
gautam
6
abcbca
3
abb
13
geeksforgeeks


1
0
1
0
*/