//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class KStacks{
    int *arr,*top,*nextfree;
    int k,curr_free,cap;

    public:
    KStacks(int cap, int k){
        arr = new int(cap);
        nextfree = new int(cap);
        this->k = k;
        top = new int(k);
        fill(top,top+k,-1);
        for(ll i = 0; i < cap; i++)nextfree[i] = i+1;
        nextfree[cap-1] = -1;
        curr_free = 0;

    }
    void push(int sn, int x){
        int index = curr_free;
        curr_free = nextfree[index];
        nextfree[index] = top[sn];
        top[sn] = index;
        arr[index] = x;
    }
    int pop(int sn){
        int index = top[sn];
        top[sn] = nextfree[index];
        nextfree[index] = curr_free;
        curr_free = index;
        return arr[index];
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    KStacks s(5,3);
    s.push(1,10);
    s.push(1,20);
    s.push(2,100);

    s.pop(1);

    


    return 0;
}