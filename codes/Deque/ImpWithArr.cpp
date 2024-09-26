//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long



class Deque{
    public:
    int *arr, cap;
    int size;
    int rear,front;
        Deque(int c){
            arr = new int(c);
            cap = c;
            rear = front = -1;
            size = 0;
        }
        int sz(){
            return size;
        }
        bool isEmpty(){
            return size == 0;
        }
        bool isFull(){
            return size == cap;
        }

        int getFront(){
            if(isEmpty())return -1;
            return front;
        }

        int getRear(){
            if(isEmpty())return -1;
            return (front+size-1)%cap;
        }
        
        void insertAtRear(int x){
            if(isFull()){
                return;
            }
            if(isEmpty())front = (front+1)%cap;
            rear = getRear();
            rear = (rear + 1)%cap;
            arr[rear] = x;
            size++;

            
                        
        }
        void insertAtFront(int x){
            if(isFull()){
                return;
            }
            if(isEmpty())front = (front+1)%cap;

            int idx = (cap+(front-1))%cap;
            front = idx;
            arr[front] = x;
            size++;

            
                        
        }
   

        int deleteFromFront(){
            if(isEmpty()){
                return -1;
            }
            int x = arr[front];
            front = (front+1)%cap;
            size--;
            return x;
        }

        int deleteFromRear(){
            if(isEmpty()){
                return -1;
            }
            rear = getRear();
            int x = arr[rear];
            rear = (cap+(rear-1))%cap;
            size--;
            return x;
        }


      
};

void print(Deque q){
    while(!q.isEmpty()){
        cout<<q.deleteFromFront()<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Deque q(7);

    q.insertAtRear(1);
    q.insertAtRear(2);
    q.insertAtFront(3);
    q.insertAtRear(4);
    q.insertAtFront(5);

    print(q);

    cout<<q.deleteFromFront()<<endl;
    cout<<q.deleteFromRear()<<endl;

    q.insertAtRear(10);
    print(q);




    return 0;
}

/*

O/P

5 3 1 2 4 
5
4
3 1 2 10


*/