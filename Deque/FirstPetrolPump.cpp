//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long



ll firstPetrolPump(vector<ll> p, vector<ll> d, int n){


    for(int start = 0; start < n; start++){

        int curr = 0;
        int end = start;

        while(true){
            curr += p[end]-d[end];
            if(curr < 0)break;

            end = (end+1)%n;
            if(end == start){
                return start+1;
            }
        }

    }
    return -1;
}

//Better using deque DS
ll firstPetrolPumpBetter(vector<ll> p, vector<ll> d, int n){

    deque<int> dq;
    int curr = 0;

    for(int end = 0; end < n; end++){

            curr += p[end]-d[end];
            if(curr >= 0){
                dq.push_back(end);
            }
            else{
                while(!dq.empty() && curr < 0){
                    ll idx = dq.front();
                    curr += (-(p[idx]+d[idx]));
                    dq.pop_front();
                }
            }

        

    }
    return (dq.empty())? -1 : dq.front()+1;
}

//we can reduce AS O(N) in better soln easily simpply by maintaining two var si and ei instead pushback we do ei++ and popfront we do si++ and atlast return (si<=ei)?si+1:-1;



//Efficient soln req O(N)opn and sigal traversal with AS O(1)
ll firstPetrolPumpEfficient(vector<ll> p, vector<ll> d, int n){

    int start = 0;
    int prev = 0;
    int curr = 0;

    for(int i = 0; i < n; i++){

            curr += p[i]-d[i];
            if(curr < 0){
                start = i+1;
                prev += curr;
                curr = 0;
            }
    }
    return (curr + prev >= 0)? start+1 : -1;
}






int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        vector<ll> petrol(n);
        vector<ll> dist(n);

        for(ll i = 0; i < n; i++){
            cin>>petrol[i];
        }
        for(ll i = 0; i < n; i++){
            cin>>dist[i];
        }

        // cout<<firstPetrolPump(petrol,dist,n)<<endl;
        // cout<<firstPetrolPumpBetter(petrol,dist,n)<<endl;
        cout<<firstPetrolPumpEfficient(petrol,dist,n)<<endl;
    
        
    
    }


    return 0;
}

/*
I/P
3
4
4 8 7 4
6 5 3 5
2 
4 8
5 6
3
8 9 4
5 10 12

O/P
2
2
-1
*/