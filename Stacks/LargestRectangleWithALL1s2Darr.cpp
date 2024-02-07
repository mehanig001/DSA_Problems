//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long


//Naive method TC O(Rcube * Ccube) take every element of 2d arr as top left most element of rectangle and process all size rectangles possible




//Efficint using largest area histogram method : for each row make a histogram arr and calc its largest area and take max one
//Note jab 0 neeche hoga to us area ko include krne ka matlab nahi hai


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

ll largestRectAll1s(vector<vector<ll>> &v,ll n, ll m){

    //first row wala histogram to waise hi rahega
    ll maxi = largestAreaEfficient(v[0],m);

    for(ll i = 1; i < n; i++){
        for(ll j = 0; j < m; j++){
            if(v[i][j] == 1){
                v[i][j] += v[i-1][j]; //kuch nahi bas prev height ko ek se badha rahe hai
            }

        }
        //ab hisogram calc ho chuka hai curr row k liye
        maxi = max(maxi,largestAreaEfficient(v[i],n));
    }

    return maxi;


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> v(n,vector<ll>(m));

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                cin>>v[i][j];
            }
        }

        cout<<largestRectAll1s(v,n,m)<<endl;
        
    
    }


    return 0;
}