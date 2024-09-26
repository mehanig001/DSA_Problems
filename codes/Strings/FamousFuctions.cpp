//<-----------------------------SSDN------------------------------>
#include<bits/stdc++.h>
#define ll long long
using namespace std; 

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
        

        cout<<"size "<<str.length()<<endl;
        str.erase(0,2); 

        // str.erase(str.begin(), str.begin()+2); //Works same
        cout<<"erasing 1st 2 chars:"<<str<<endl;

        auto f = str.find("tam");
        if(f>=0 && f<n){
            cout<<"YES tam is present: "<<f<<endl;
        }
        else{
            cout<<"tam is not present"<<endl;
        }

        for(auto &ch : str){
            ch = tolower(ch);

        }
        cout<<"After Lower Case "<<str<<endl;

        string sub = str.substr(1,3);
        cout<<"substring from idx 1 of size 3 "<<sub<<endl;


        
    }

    return 0;
}

/*


I/P
4
6
Gautam
6
MehanI
6
rishaB
7
tik-tok



O/P
size 6
erasing 1st 2 chars:utam
YES tam is present: 1
After Lower Case utam
substring from idx 1 of size 3 tam
size 6
erasing 1st 2 chars:hanI
tam is not present
After Lower Case hani
substring from idx 1 of size 3 ani
size 6
erasing 1st 2 chars:shaB
tam is not present
After Lower Case shab
substring from idx 1 of size 3 hab
size 7
erasing 1st 2 chars:k-tok
tam is not present
After Lower Case k-tok
substring from idx 1 of size 3 -to

*/