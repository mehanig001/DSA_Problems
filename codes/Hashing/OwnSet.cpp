//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long


int binSearch(vector<int> &v, int key){
    int si = 0, ei = v.size()-1;
    while(si <= ei){
        int mid = si + (ei-si)/2;
        if(v[mid] == key)return mid;
        else if(v[mid] > key)ei = mid-1;
        else si = mid+1;
    }
    return -1;
}


class Set{
    vector<int> v;
    public:
        bool empty(){
            return v.empty();
        }
        int size(){
            return v.size();
        }
        void insert(int n){
            v.push_back(n);
            sort(v.begin(), v.end());
        }

        int find(int n){
            return binSearch(v,n);
        }

        void erase(int n){
            v.erase(v.begin() + binSearch(v,n), v. begin() + binSearch(v,n) +1);
        }

        void print(){
            for(auto val : v){
                cout<<val<<" ";
            }
            cout<<endl;
        }

        int getSmallest(){
            if(v.empty())return INT_MAX;
            else return v[0];
        }

        int getLargest(){
            if(v.empty())return INT_MIN;
            else return v.back();
        }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Set s;

    s.insert(4); //O(N)
    s.insert(1);
    s.print(); //O(N)

    s.insert(2);
    s.print();

    s.insert(9);
    s.insert(4);
    s.print();

    s.insert(3);
    s.insert(5);
    s.print();

    cout<<s.find(4)<<endl;
    s.erase(4);
    s.print();



    cout<<s.getSmallest()<<endl;
    cout<<s.getLargest()<<endl;

    //can you reduce insertion time complexity to logn      
    


    return 0;
}