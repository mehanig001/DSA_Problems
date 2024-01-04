#include<bits/stdc++.h>
using namespace std; 
void print(map<int,string> m){
    //size funcn kam krega
    cout<<m.size()<<endl;
    //print krne ke liye itr define kr skte h ya direct auto keyword se bhi kr sakte hai
    for(auto pr : m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}

int main(){
    //map stores value in key-value pair form 
    //by default it stores value in ascending or lexographically inc order according to key

    //initialization
    map<int,string> m;
    m[2] = "abc";  //insertion TC O(logn) when key is int
    m[5] = "def";
    m[7] = "abc";

    m[5] = "jkl";  //keys are unique therefore purani 5 ki value me change hoga

    print(m);
    

    // //key ko ham string bhi rkh skte h
    // map<string,string> m1 = { {"a","abc"}, {"d","bd"}, {"c","kk"} ,{"z", "gg"} };  //isme hr string compare hogi insertion se phle
    // //insertion TC O(size of string of key * logn);

    // cout<<m1.size()<<endl;
    // for(auto pr: m1){
    //     cout<<pr.first<<" "<<pr.second<<endl;
    // }

    

    //insert
    m.insert({8,"ck"});
    print(m);

    //finding value by using itr and key both
    auto it = m.find(3);
    if(it == m.end()){
        cout<<"not exist\n";
    }
    else{
        cout<<it->first<<" "<<it->second<<endl;
    }

    //erase
    m.erase(8);
    print(m);

   
    /*
    //Question : Given n strings you have to print unique strings in lexographically order with their freq
    int n;
    cin>>n;
    
    map<string,int> mp;  //s,int ka isliye kuki strings unique dikhani h
    for(int i = 0; i < n; i++){
        string s;
        cin>>s;

        mp[s]++;
    }

    for(auto pr : mp){
        cout<<pr.first<<" "<<pr.second<<endl;
    }


    */


    //Unordered Maps

    //inbuilt implementation ---> insertion or access find or erase TC O(1) ho jati h aur ye red black tree n use krke hashing table use krta h
    //kyuki y hashing use krta h isliye unordered_map<pair<int,int>,strings> nhi bn payega pair ki hashing predefined nhi h



    //direct ek que se smjhte h upar wale que me agar lexographically order hata de

    unordered_map<string,int> um;
    cout<<"enter the size of inputs : ";
    int s; //size of um
    cin>>s;
    for(int i = 0; i < s; i++){
        string str;
        cin>>str;

        um[str]++;  //sort nhi hoga random order m fill hoga ++ freq count kr lega by default 0 value hoti h int k case m

    }

    //ab kuch query di h sirf unki freq batani h
    cout<<"enter no of queries then string repectively : ";
    int q;
    cin>>q;
    for(int i = 0; i < q; i++){
        string str;
        cin>>str;
        cout<<um[str];
    }

    cout<<endl;
    //maps ke case m kya tha ki ek ki do ya jada value nhi ho skti 
    //multimap me ek key ke corresponding multiple values ho skti h

    multimap<int,int> mm;
    mm.insert({1,100});
    mm.insert({1,200});
    mm.insert({2,100});
    mm.insert({1,500});
    for(auto i: mm){
        cout<<i.first<<" "<<i.second<<"   ";
    }

// the thing which we can do instead of defining multimap is map<int,vector<int>> in above case







    return 0;
}