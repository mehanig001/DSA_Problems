# Deque
---

Basic operations: 
insertAtFront(), insertAtRear(), deleteFromFront(), deleteFromRear(), getFront(), getRear(), isFull(), isEmpty(), size();


### Applications
 - Can be used as both stack and queue
 - Maintaining history of actions
 - Steal process scheduling algo -> khali processor bhare processor ka kuch kaam - thread execute kr dega
 - as a priority queue
 - max and min of all subarrays in size k


<br>

---
### Problems & Codes
---


#### [Implementation using fixed circular array](Deque/ImpWithArr.cpp)
<details>
<summary>Hint</summary>

    
    data members: int*arr, int cap, int size, int front, int rear sometimes, 

    hint using cap define arr = new int(n);
    Make sure to update front and rear in deque and enque operations correctly when reaquired to handle this situation it is recomended to maintain an isEmpty() 
    while doing Front = (Front-1)%cap do Front = (cap+Front-1)%cap to avoid negative values while inserting at front 
    similarily while deleting from rear do rear = (cap+rear-1)%cap



</details>

#### [Implementation using STL](Deque/DequeInSTL.cpp)
<details>
<summary>Hint</summary>

    
    it maintains array of pointers pointing to so many fixed size arrays and then first the middle ptr will point to the middle most arr and start filling values if fulls while inserting at rear it uses next ptrs array just below prev arr and while adding items in front it uses upper ptr's array 

    syntax: deque<int> dq;
    opn: push_back(), push_front(), pop_back(), pop_front(), front(), back(), size(), empty(), begin(), end(), rbegin(), r.end()....


    Question implement a DS that will have following funcn insertMin(int x), insertMax(int x), getMin(), getMax(), delete also
    Given: x given will be less than already min present and for insertMax it will be larger than max val present in DS



</details>

#### [Find Max in all sub arr of size k using space complexity O(K)](Deque/MaxInAllSubarrOfSizeK.cpp)
<details>
<summary>Hint</summary>

    
    Naive: In O(Nsq) for all possible subarrays find max value and print n-k+1 values

    Optimized:
        for first window that is from i = 0; to i < k; i++ 
            jab tak arr[i]>=arr[dq.back()] ---> dq.pop_back();
        
            dq.push_back(i)
        
        for(i = k; i < n; i++)
            first print arr[dq.front()]<<" "

            then removing wo elements jinka idx kam hai matlab jo is window me nahi hai
            while(dq.front() <= i-k && !dq.empty())
                dq.pop_front()
            
            then remove all unnecessary items jo aage ke liye answer ho hi nahi sakte agar arr[i] aa jaye to 
            while(!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back()

            then push curr idx
            dq.push_back(i)

        
        print one last windows max element
        cout<<arr[dq.front()]<<endl;






</details>

#### [First Circular Tour PetrolPumpsCap and Distance](Deque/FirstPetrolPump.cpp)
<details>
<summary>Hint</summary>


    Problem: Consider an arrangement where n petrol pumps are arranged in a circular manner. We need to find the first petrol pump from where we can visit all petrol pumps and come back to the petrol pump without ever going out of the petrol.


    Naive Soln: 
        O(Nsq) consider every petrol pump as starting point if somewhere currpetrol becomes negative this cant be starting point similarly check for all if somewhere ans exist return idx +1  if we came out of loop we found no starting point that will complete the circular arr return -1

    Better Soln:
        O(N) and Aux space also O(N) 
        create an empty dq

        if(curr < 0) at some point start pop_front items until dq become empty or curr become >=0
        else push_back idx

        return dq.front()+1 if(dq is not empty) else -1

        We can reduce extra aux space simply be maintain two var si and ei 
        instead pushback we do ei++
        and instead popfront we will do si++;
    
    Efficient one:
        Require O(N)TC and Single Traversal 
        If curr Pi becomes -ve then from Pzero to Pi no one will be the ans store prev petrol here to know circular extra amount to travel from last idx to avoid retraversal

        for better understanding see code




</details>
