# Queue
---
**FIFO First IN FIRST OUT** <br>
Basic operations: enque(), deque(), empty(), size(), getFront(), getRear(), isFull();


### Applications
 - Single Resource Multiple Consumers
 - Synchronization between slow and fast devices
 - In Operating Systems (FCFS scheduling, buffers for devices like keyboard)
 - In Computer Networks (Routers, Switches)

Variations: Doubly Ended Queue, Circular Queue, Prioirity Queue

<br>

---
### Problems & Codes
---


#### [Implementation using fixed size array](codes/Queue/ImplementationArray.cpp)
<details>
<summary>Hint</summary>

    
    data members: int*arr, int cap, int size, int front, int rear sometimes, 
    hint using cap define arr = new int(n);
    Make sure to update front and rear in deque and enque operations correctly when reaquired to handle this situation it is recomended to maintain an isEmpty() 



</details>

#### [Implementation using LinkedList](codes/Queue/ImplementationWithLinkedList.cpp)
<details>
<summary>Hint</summary>

    
    data members: Node *head, *rear; int size 
    hint using constructor head = rear = NULL and size = 0

    Wrong way is to choose rear as head and front as last element because when we try to deque front element we will require second last element

    Right way is to deque means delete from head 
    enque means insert after rear 
    update front rear and size accordingly handling corner cases



</details>

#### [Stack Using Queue](codes/Queue/ImplementStackUsingQueue.cpp)
<details>
<summary>Hint</summary>

    
    3 ways:
        By making push opn costly: first copy all elements to q2 and then push in q1 then copy back all from q2 to q1
        By making pop opn costly
        By using recrsn and single queue: think later




</details>

#### [Reverse Queue](codes/Queue/ReversingAQueue.cpp)
<details>
<summary>Hint</summary>

    
    Iterative: Using aux stack push all items to stack then enque them back to queue

    Recursive: suppose we have reversed next n-1 elements what we have to do is 
                deque first element and enque it to the last 
                base case will be if q is empty return;



</details>

#### [Generate Numbers With Given Digits In Increase Order](codes/Queue/GenerateNumbersWithGivenDigitsInc.cpp)
<details>
<summary>Hint</summary>

    suppose we have to generate digits 5 6 55 56 65 66 555 556 565 566 
    first we push 5 and 6 to queue q
    then for i = 0; i < count; i++
        we will store curr = q.top(); //front element and print it to get ith term
        and q.pop();
        
        q.push(curr+"5");
        q.push(curr+"6);


    


</details>
