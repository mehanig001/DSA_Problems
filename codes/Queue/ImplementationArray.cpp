//-------------------------------------SSDN-----------------------------------------
#include<bits/stdc++.h>
using namespace std;
#define ll long long


// Simple Implementation we are wasting space in dequeuq operation

// class Queue{
//     int *arr, cap;
//     int rear,front;
//     public:
//         Queue(int c){
//             arr = new int(c);
//             cap = c;
//             rear = front = -1;
//         }
//         void enqueue(int x){
//             if(rear == -1){
//                 front++;
//             }
//             rear++;
//             if(rear == cap)
//                 cout<<"Queue is already Full"<<endl;
//             else
//                 arr[rear] = x;
            
//         }

//         int dequeue(){
//             if(front == -1 || front > rear)cout<<"Queue is already empty"<<endl;
//             else{
//                 int x = arr[front];
//                 front++;
//                 return x;
//             }
//             return -1;
//         }

//         int getFront(){
//             if(front != -1 && front <= rear){
//                 return arr[front];
//             }
//             return -1;
//         }

//         int getRear(){
//             if(front != -1 && front <= rear){
//                 return arr[rear];
//             }
//             return -1;
//         }
//         int size(){
//             if(front == -1 || front > rear)return 0;
//             else return rear-front+1;
//         }
//         bool isEmpty(){
//             if(front == -1 || front > rear)return 1;
//             else return 0;
//         }
//         bool isFull(){
//             return rear == cap-1;
//         }
// };


//To use space we can shift all elements to left and maintain front as 0 always but dequeue cost O(n) time

//To do it in O(1) we can use concept of circular array
//rear = (front + size -1) % cap

class Queue{
    public:
    int *arr, cap;
    int size;
    int rear,front;
        Queue(int c){
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
        
        void enqueue(int x){
            if(isFull()){
                return;
            }
            if(isEmpty())front = (front+1)%cap;
            rear = getRear();
            rear = (rear + 1)%cap;
            arr[rear] = x;
            size++;

            
                        
        }

        int dequeue(){
            if(isEmpty()){
                return -1;
            }
            int x = arr[front];
            front = (front+1)%cap;
            size--;
            return x;
        }


      
};

void print(Queue q){
    while(!q.isEmpty()){
        cout<<q.dequeue ()<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    Queue q(7);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    print(q);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.enqueue(10);
    print(q);




    return 0;
}

/*

O/P

1 2 3 4 5 
1
2
3 4 5 10


*/