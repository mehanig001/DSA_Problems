//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isOperand(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))return true;
    return false;
}


int evalPostfix(string str){
    stack<int> st;
    for(ll i = 0; i < str.size(); i++){
        char ch = str[i];
        if(isOperand(ch)){
            st.push(ch-'0');
        }
        else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            int val = 0;
            if(ch == '+')val = op1+op2;
            else if(ch == '-')val = op1-op2;
            else if(ch == '*')val = op1*op2;
            else if(ch == '/')val = op1/op2;
            else if(ch == '^')val = pow(op1,op2);

            st.push(val);
        }

    }
    return st.top();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
    while(t--){
      
        string str;
        cin>>str;

        cout<<evalPostfix(str)<<endl;

    
        
    
    }


    return 0;
}

/*
I/P
5
23*5+
235*+
23+5*
23+5-
1234*22/+++


O/P
11
17
25
0
16
*/