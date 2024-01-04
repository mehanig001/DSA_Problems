#include<bits/stdc++.h>
using namespace std; 

void print(set<string> &s){
    cout<<s.size()<<endl;
    for(auto value: s){
        cout<<value<<"  ";
    }
    cout<<endl;
}
void print(unordered_set<string> &s){
    cout<<s.size()<<endl;
    for(auto value: s){
        cout<<value<<"  ";
    }
    cout<<endl;
}
void print(multiset<string> &s){
    cout<<s.size()<<endl;
    for(auto value: s){
        cout<<value<<"  ";
    }
    cout<<endl;
}


int main(){
    //set is same as map but it stores only one type by default in sorted manner
    set<string> s;  ///kisi bhi complex datatype ka set bana skte h jaise ki set<pair>
    s.insert("abc"); //TC insert ke liye O(logn) kyuki sorted me store kr raha hai
    s.insert("bbc");
    s.insert("sfdc");
    s.insert("abc");  //repeated elemnts hat jate h normal set se
    s.insert("cpa");
    s.insert("xyz");

    set<string> :: iterator it = s.begin();

    print(s);

    auto it = s.find("erp");  //gar element nhi milega to end() par phuch jayega itrator segmentation fault ke chances h
    if(it != s.end())
    cout<<*it<<endl;

    //erase krne ke do tarike h 1(itrator) aur dusra direct value pass krke
    if(it != s.end())
    s.erase(it);

    s.erase("xyz");  //yaha to thik h pr multiset m it ka use krna chahiye

    print(s);


    //size aur clear funcn to sabhi containers me kam krenge


    //UNORDERED SET : bole to sorted me nhi hoga mtlb TC kam lega insert ki bhi access ki bhi O(1)
    //sorted ki jarurat n ho to unordered hi use krna kyuki TC matters

    unordered_set<string> us ;  //iske andar complex datatypes nhi de skte kyuki y tree nhi hash table wali algo use krta h
    us.insert("xag");
    us.insert("abc");  //O(1)
    us.insert("tuv");
    us.insert("kal");  //repeated element to y bhi ni lega 



    print(us);  //random order m print krega


    //baki same operation isme bhi kr skte h find aur erase wale



    //MULTISET : bole to same value bhi chlegi aur sorted me bhi milegaa
    //Que me use krne se phle soch lena set use krna h ki multiset

    multiset<string> ms;
    ms.insert("xag");
    ms.insert("abc");  //O(logn)
    ms.insert("abc");  
    ms.insert("abc");  
    ms.insert("tuv");
    ms.insert("kal");

    print(ms);

    //find wo iterator deta h jaha par value ka first occurance hota h jaise idhr abc ka first occ begin m h
    //erase - idhar erase krne k liye itrator ka use krna kyuki value doge to sari duplicates uda dega ho skta h tumhe unka kam pade

    //jaise
    auto itr = ms.find("abc");
    ms.erase(itr); //O(1) kyuki itr diya h 
    print(ms);


    ms.erase("abc"); //log(n) aur sare abc delete ho jayenge
    print(ms);



//Que h ki given set ho strings me se unique string print krna hi lexographically order me to set ka use kr skte h

//Que agar sirf ye batana h ki given  set me kuch given string present h ki nhi h to unordered set ka use krenge due to TC




    return 0;
}