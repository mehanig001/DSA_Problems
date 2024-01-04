# Hashing bole to O(1) in avg
<details>
<summary>Man ki baat</summary>
{
  
    Ye to bawal cheez hai be
    Search/Insert/Delete in O(1) in avg
    

}
</details>


### Direct Adress Table
<details>
<summary>Matlab</summary>
{
  
    Suppose we have to count frequency of characters appearing in a given string
    we can maintain an array of size 26 whose index will represent characters from 'a' to 'z'

    i.e. 0 for 'a' and idx of any character can be calculated via ch-'a'

    whenever we find the character we will do arr[ch-'a']++ to count it

    

}
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
{
  
    If things collide we add the next key as a next item in the same box
    DS for Storing chain are:
        Linked Lists O(L)
        Dynamic Arrays O(L)
        Self balancing trees O(log(L))
    
    m = no of slots in hash table
    n = no of keys to be inserted

    alpha = n/m (LOAD FACTOR)

    Expected Time to Search/Insert/Delete = (1 + alpha)



    

}
</details>

<details>
<summary>Open Addressing</summary>
{
    
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

    


    

}
</details>



### [Unordered Sets and more in C++ STL](Hashing/set.cpp)
### [Unordered Maps and more in C++ STL](Hashing/maps.cpp)