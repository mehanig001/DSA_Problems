//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool match(char o, char c){
    return (o == '(' && c == ')') || (o == '{' && c == '}') || (o == '[' && c == ']');
}

bool isBalancedParanthesis(string str, ll n){
    stack<char> s; //stores opening bracket
    for(ll i = 0; i < n; i++){
        char x = str[i];
        if(x == '(' || x == '{' || x == '[')s.push(x);
        else{
            if(s.empty())return false;
            char top = s.top();
            if(!match(top,x)){
                return false;
            }
            else s.pop();
        }

    }
    return s.empty();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
    
        string str;
        cin>>str;

        bool ans = isBalancedParanthesis(str,n);
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    
    }


    return 0;
}

/*
I/P
6
3
()(
8
{[{}]()}
4
((()
4
()))
2
()
10
}{{}}}()[]


O/P
NO
YES
NO
NO
YES
NO

*/