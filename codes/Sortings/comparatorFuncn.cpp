#include<bits/stdc++.h>
using namespace std; 


// aise krna hai ki pahle int inc order m ho agar same h to string dec order m ho
bool cmp(pair<int,string> a,pair<int,string> b){
    if(a.first != b.first) return a.first < b.first;   //basically phle chota chaiye to return kr dete h a ka phla chota b ke phle se
    else{
        return a.second > b.second;
    }
}

//phle k according dec aur dusre ke acc inc agr same ho to
bool cmp2(pair<int,string> a,pair<int,string> b){
    if(a.first != b.first) return a.first > b.first;
    else{
        return a.second < b.second;
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,string>> v(n);
    vector<pair<int,string>> :: iterator it = v.begin();
    for(it;it!=v.end();it++){
        int a;
        string b;
        cin>>a>>b;
        it->first = a;
        it->second = b;
    }
    sort(v.begin(),v.end(),cmp2); //sort in ascending order whole vector
    
    it = v.begin();
    cout<<endl;
    for(it;it!=v.end();it++){
        cout<< it->first << " " << it->second<<endl;
    }
    return 0;
}