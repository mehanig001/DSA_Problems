//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isOperand(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))return true;
    return false;
}

int precendence(char a){
    if(a == '^')return 3;
    else if(a == '*' || a == '/')return 2;
    else if (a == '+' || a == '-')return 1;
    else return 0;
}

string postfix(string str){
    string ans = "";
    stack<char> st; //for operators

    for(int i = 0; i < str.size(); i++){
        char ch = str[i];
        if(isOperand(ch)){
            ans += ch;
        }
        else{
            if(ch == '('){
                st.push('(');
            }
            if(ch == ')'){
                while(!st.empty()){
                    char top = st.top();
                    if(top == '('){
                        st.pop();
                        break;
                    }
                    ans +=top;
                    st.pop();
                }
            }
            if(ch != '(' && ch != ')'){
                //operator
                if(st.empty()){
                    st.push(ch);
                }
                else{
                    char top = st.top();
                    if(precendence(ch)>precendence(top)){
                        st.push(ch);
                    }
                    else{
                        while(!st.empty() && precendence(st.top()) >= precendence(ch)){
                            char top = st.top();
                            st.pop();
                            ans += top;
                        }
                    }
                }

            }
        }
    }
    while(!st.empty()){
        char top = st.top();
        ans+=top;
        st.pop();
    }
    return ans;
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

        cout<<postfix(str)<<endl;
    
        
    
    }


    return 0;
}

/*
I/P
5
5
a+b*c
7
(a+b)*c
3
a*b^c
2
a*b
8
a+b*c+d/e

O/P
abc*+
ab+c*
abc^*
ab*
abc*+de/

*/