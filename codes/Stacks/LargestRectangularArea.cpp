//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long


vector<ll> prevLower(vector<ll> &v, ll n){
    vector<ll> ans;
    stack<ll> s;
    s.push(0);
    ans.push_back(-1);

    for(ll i = 1; i < n; i++){
        while(!s.empty() && v[s.top()] >= v[i])s.pop();
 
        if(s.empty())ans.push_back(-1);
        else ans.push_back(s.top());//we are pushing idx here

        s.push(i);
    }

    return ans;
}


vector<ll> nextLower(vector<ll> &v, ll n){
    vector<ll> ans;
    stack<ll> s;
    s.push(n-1);
    ans.push_back(n);

    for(ll i = n-2; i >= 0; i--){
        while(!s.empty() && v[s.top()] >= v[i])s.pop();

        if(s.empty())ans.push_back(n);
        else ans.push_back(s.top());

        s.push(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//Naive sik jya hoga ki har i ke liye i-1 to 0 tak aur i+1 to n tak jayenge for calc prev and next smaller TC O(Nsq)


//TC O(N) req 3 Traversal and O(N)aux space also for vectors
ll largestArea(vector<ll> &v){
    vector<ll> prev = prevLower(v,v.size()); //for storing idx of prev lower elements
    vector<ll> next = nextLower(v,v.size()); //for storing idx of next lower elements

    for(auto val: prev)cout<<val<<" ";
    cout<<endl;

    for(auto val: next)cout<<val<<" ";
    cout<<endl;

    ll res = 0;

    for(ll i = 0; i < v.size(); i++){
        ll curr = v[i];
        curr += (i-prev[i]-1)*v[i];
        curr += (next[i]-i-1)*v[i];

        res = max(res,curr);
    }


    return res;
}

//Efficient approach that req only 1 traversal and only aux space for 1 stack 
ll largestAreaEfficient(vector<ll> &v, ll n){
    //storing idx in stack in such a way that upar wala value ascending order me ho
    stack<ll> st;
    st.push(0);
    ll maxi = 0;


    for(ll i = 1; i < n; i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            ll tp = st.top();
            st.pop();

            ll curr = v[tp] *( st.empty()? i : (i-st.top()-1));
            maxi = max(curr,maxi);
        }
        st.push(i);
    }

    //processing remaining element replacing i with n
        while(!st.empty()){
            ll tp = st.top();
            st.pop();

            ll curr = v[tp] *( st.empty()? n : (n-st.top()-1));
            maxi = max(curr,maxi);
        }

        return maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector <ll> v(n);
        for(ll i = 0; i < n; i++){
            cin>>v[i];
        }
    
        cout<<largestArea(v)<<endl;
        cout<<largestAreaEfficient(v,n)<<endl;
    
    }


    return 0;
}