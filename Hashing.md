# Hashing bole to O(1) in avg
<details>
<summary>Man ki baat</summary>

  
    Ye to bawal cheez hai be
    Search/Insert/Delete in O(1) in avg
    


</details>


### Direct Adress Table
<details>
<summary>Matlab</summary>

  
    Suppose we have to count frequency of characters appearing in a given string
    we can maintain an array of size 26 whose index will represent characters from 'a' to 'z'

    i.e. 0 for 'a' and idx of any character can be calculated via ch-'a'

    whenever we find the character we will do arr[ch-'a']++ to count it

    

</details>

### Hash functions

These are used to decide the index of the hash table for given keys
For Example:
- h(larger_key) = larger_key % m [Where m is selected as prime ] we avoid 2 pow n because we get last n bits similarly 10
- For Strings it can be weighted sum (str[0]xpow0 + str[1]xpow1 + str[2]xpow2 + .....)
- Universal Hashing


### Application
- Dictionaries
- Database Indexing (Like B And B+ Trees)
- Cryptography (Storing Passwords)
- Caches
- Symbol Table in Compiler & Interpreters
- Routers
- Getting data from database
- and many more


## Collisions & Handling

Like Birthday Paradox Collisions are bound to happen 

Two Popular ways of collision handing
<details>
<summary>Chaining</summary>

  
    If things collide we add the next key as a next item in the same box
    DS for Storing chain are:
        Linked Lists O(L)
        Dynamic Arrays O(L)
        Self balancing trees O(log(L))
    
    m = no of slots in hash table
    n = no of keys to be inserted

    alpha = n/m (LOAD FACTOR)

    Expected Time to Search/Insert/Delete = (1 + alpha)



    


</details>

<details>
<summary>Open Addressing</summary>

    
    Cache Freindly
    We find next available slot to insert elements in hash table using these Probing

    Three types:
        - Linear
        - Quadratic
        - Double Hashing

    Condition
        - No of slots in hash table >= No of keys to be inserted

    Avg time O(1/(1-alpha))
    
    For Inserting If hash value calc is empty means -1 or something was their but deleted means -2 we insert at the same
    but if not empty then we use any of the above three methods to find empty slots

    For Searching we search until key is found or covered whole table or found -1 but not stop in -2

    For Deletion Simply search and replace with -2 to avoid problems


    CLUSTERING: Problem with linear hashing 
    Clusters keep on increasing in linear probing where hash(key) = (hash(key) + i)%m 
    We can use quadratic probing to reduce this where hash(key) = (hash(hey + isq)%m)
        -But problem with this is it may not found an empty slot present in hash table
    
    Double Hashing: Performs better than them here hash(key) = (hash1(key) + i*hash2(key))%m
        -both hash fuctions should relatively prime

    


    


</details>



### [Unordered Sets and more in C++ STL](Hashing/set.cpp)
### [Unordered Maps and more in C++ STL](Hashing/maps.cpp)



#### [Intersection Of 2 unsorted Arrays](Hashing/IntersectionsOf2UnsortedArr.cpp)
<details>
<summary>Hint</summary>

  
    Use unordered_set first insert values of 1 array 
    then find val is already present in set for every value in other array
    



</details>


#### [Union Of 2 Unsorted Arrays ](Hashing/Union2UnsortedArr.cpp)
<details>
<summary>Hint</summary>

  
    Insert all values in unordered_set and print them



</details>


#### [Pair With Given Sum Exist Or Not](Hashing/PairWithSumExist.cpp)
<details>
<summary>Hint</summary>

    
    Sort the array and using two pointers if(v[l]+ v[r]) == sum  > or <  work accordingly until l<r
    O(NlogN)

    first unordered_set<ll> s(v.begin(),v.end());
    traverse array and for every value  
    s.erase(val)
    if(s.find(sum-val) != s.end()) return true;


    if(traversed whole array return false)

    Alter:  insert elements in new unordered set before this check if sum - v[i] is already present in set if yes then print yes
    



</details>

#### [Subarray With Zero Sum Exist Or Not](Hashing/SubarrWithZeroSum.cpp)
<details>
<summary>Hint</summary>

    
    Naive: O(Nsq) take every ith element as the begining element of the subarray and check for the zero sum taking all possible subarray sum including from j = i+1 to j < n 


    Alter: Use of Prefix sum And Unordered Set O(N) Aux Space O(N)
    We can calc the prefix sum of given array and if it satisfy and of two conditions given below ans is yes
    1->prefix sum at any point is zero 
    2->prefix sum is same for any two values i.e. p1 + 0 = p2  (p1 = p2)
    
    to chk this we maintain an unordered_set and chk for the presence of elements before inserting pre val into it



</details>

#### [Subarray With Given Sum Exist Or Not](Hashing/SubArrWithGivenSum.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol is same we have to chk every subarray sum possible in O(Nsq)

    Alter: Prefix Sum + Unordered_set
    Calc Prefix sum and if p1 + sum = p2  or p[i] == sum
    means difference of any two prefix sum equals to given sum and is yes
    
    to chk this we maintain an unordered_set and before inserting value of pre[i]
    we will chk if(pre[i] == sum) OR pre[i]-sum is already present in set or not




</details>


#### [Return Length Of Longest Subarray With Given Sum](Hashing/LongestSubarrayWithGivenSum.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol is same we have to chk every subarray sum possible & take maxlength in O(Nsq)

    Alter: Longest matlab jab prefix se calculate kare to leftmost aur right most ka pair aisa kuch bane
    //First calc prefix sum and An Empty unordered map(stores: pre[i]and i for leftmost pre[i]'s)
    
    //Traverse in prefix sum
    //if prefix sum is equal to given sum at any i ans = max(ans,i+1);

    //if(map contains pre[i] - sum at any point then) ans = max(ans,i-(itr->second))

    //If map doest not contain pre[i] Then insert {pre[i],i} in map



    return ans
    




</details>


#### [Max Length Of Subarray Containing Equal 0s and 1s in Binary Arr](Hashing/LongestSubbWithEqual0sAnd1sBinaryArr.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol is same we have to chk every subarray sum possible in O(Nsq)

    Replace all 0s with -1s and find maxlegth of subarray with sum = 0 in this changed array
    to find maxlength use previous method of prefix sum and map 




</details>


#### [Longest common span with equal sum in binary arrays](Hashing/LongestCommonSpanEqualSumBinArr.cpp)
<details>
<summary>Hint</summary>

    
    We have given two same length arrays a and b
    Naive sol is same we have to chk every subarray sum possible in a equals b & take maxlength in O(Nsq)

    Alter: Longest matlab jab prefix se calculate kare to leftmost aur right most ka pair aisa kuch bane
    //Make a new vector v for all v[i] = a[i]-b[i] i.e. diff of two arrays
    //Now do the same as we were doing before, find longest subarray with sum = 0 in vector v


    //First calc prefix sum and An Empty unordered map(stores: pre[i]and i for leftmost pre[i]'s)
    
    //Traverse in prefix sum
    //if prefix sum is equal to given sum at any i ans = max(ans,i+1);

    //if(map contains pre[i] - sum at any point then) ans = max(ans,i-(itr->second))

    //If map doest not contain pre[i] Then insert {pre[i],i} in map




</details>


#### [Longest Consecutive Subsequence](Hashing/LongestConsecutiveSubsequence.cpp)
We have to return longest length of consecutive elements present in arr in any order
<details>
<summary>Hint</summary>

    
    Naive sol: Sort the array O(NlogN)

        set ctr = 1,ans = 1, prev = v[0]

            for all i = 1, i < n, i++{
                chk if v[i]==prev+1 -> {ctr++; }
                else if(v[i] != prev){reinitialize ctr = 1 and set ans = max(ans,ctr)}
                
                prev = v[i]
                ans = max(ans, ctr) for last
            }

    
    Optimized

        We first insert all the elements in unordered set then in 2*n look ups we will get req result

        for every curr element 
            if(curr-1)is already present in arr means it is not a starting val of a subseq so ignore it

            else{

                from ctr = 1, we will chk  curr+1,curr+2,curr+3,.......
                we will chk the presence of all until we do not get a result and increment ctr
                then we will take ans as max(ans,curr)
            }

        TC(O(N)){
            atmost we are looking for 2*n times see how

            2+(len -1) times for elements which are beg of any subseq, len:lenght of longest subseq with beg
            o/w 1 comp for curr-1


        }






</details>


#### [Count Distinct Elements In Every Window](Hashing/CountDistinctElementsInEveryWindow.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol is same we have to chk every window possible with an empty set and return size at last

    We can precalculate the unique elements in first window using freq of elements storing in map 

    for evry next ith element we will dec freq of i-kth element by 1 if it becomes 0 we will remove that
    and add or inc the freq count for upcoming elements 
    for every itr we will print m.size();




</details>


#### [More Than n/k occurance](Hashing/MoreThan_NbyK_occ.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol is maintain map with freq of all values and for freq>n/k print val

    Alter: O(n*k) we will either reject or select curr value let's see how

    create an empty unordered_map
    for(i = 0, i < n, i++){
        if(v[i]) is present in map m[v[i]]++

        else if(not present but m.size() < k){
            m.insert({v[i],1});
        }
        else{
            Decrement all values freq by 1 and if it becomes zero remove that element from the map

        }
    }

    //Check if remaining elements in m are acutal ans or not by recounting theri freq 
    if freq>n/k print them 



</details>

