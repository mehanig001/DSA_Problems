## Sortings 

### sort() in STL

STL in C++ uses IntroSort which is basically a combination of Quick, Heap and Insertion Sort
It's worst case TC is O(NlogN)
It first uses quick sort and if unneccessary recusive function call takes place it switches to head sort and when input size becomes small it switches to insertion sort<br>

SYNTAX: sort(v.begin(),v.end()) we pass itr from beg to one more than the last element for arr it is arr,arr+n

For Customized sorting we can use comparator functions such as greater<int>
sort(v.begin(),v.end(),greater<int>) this will sort given vector in descending order 

Here is example of comparator function for better understanding

#### [Comparator Functions](Sortings/comparatorFuncn.cpp)

### Stability in a sorting algo

[("Anil",50), ("Ayan",80), ("Piyush",50), ("Ramesh",80)]

If two items have same value then after sorting they must appear in the order as that in orignal array

After sorting for int values Anil must comes before Piyush AND Ayan before Ramesh

Some Stable Sortings are:<br>
- Bubble if(v[j]>v[j+1]) so equal val remains at pos<br>
- Insertion while(prev >= 0 && curr < v[prev]) same here<br>
- Merge if(v[i] <= v[j]) temp[k++] = v[i++]<br>

Unstable are:<br>
- Selection<br>
- Quick<br>
- Heap<br>

### Codes 

#### [Bubble Sort](Sortings/BubbleSort.cpp)
<details>
<summary>Hint</summary>
{
    //TC = O(Nsq)

    for each i before n-1
        chk if v[j] > v[j+1] then swap up to n-1-i 
    
    Can Use isSwapped boolean var to optimize the code 

}

</details>

#### [Selection Sort](Sortings/SelectionSort.cpp)
<details>
<summary>Hint</summary>
{
    TC: O(Nsq) even in best case

    Less memory writes as compared to other famous algo except Cycle Sort

    Basic idea for implementation of Heap Sort

    Not Stable AND In Place Algo (Means no extra space required)

    IDEA IS:

    for i = 0 to n-1 loop 
    let a tempidx = i
    we will find the idx of element in j var loop that should be in ith index in Sorted Array
        example when arr is sorted we will find next minimum element
    
    after second loop we will swap the v[i] with v[tempidx]

}

</details>

#### [Insertion Sort](Sortings/InsertoinSort.cpp)
<details>
<summary>Hint</summary>
{
  
    TC: O(Nsq) Big O(n) in best case when arr is already sorted
    Inplace and Stable
    Used in practise for small n

    IDEA:

    We know that a single element is always sorted so we assume 0th idx as sorted part

    then we start i from 1 and store curr val and prev idx as i-1

    while(prev >= 0 && curr < v[prev]) is used to find the correct position and shift other for placing curr in sorted part
    
    then we insert curr at sorted part by using v[prev+1] = v[prev];

    Every time length of sorted part inc by 1

}

</details>

#### [Merge Sort](Sortings/MergeSort.cpp)
<details>
<summary>Hint</summary>
{
  
  Divide and Conquer, Stable, O(nlogn) and O(n) aux space [Alloc and Dealloc]
  Well suited for linked list works in O(1) aux space
  Used in external sorting
  In general for arrays quick sort outperforms due to fast random access

  IDEA:
    Recurisively merge sort will sort left part of arr ,i.e. si to mid
                    and right part ,i.e. mid+1,ei
        
    Finally we have to implement a merge funcn that will merge two sorted parts as merge(v,si,mid,ei)
        Merge() will use a temp arr to store sorted items and itr k to traverse on it
                itr i to treverse in left and j for right

                firstly it will copy smaller elements from both arrays until one of them gets empty
                then it will copy remaining elements to temp

                Finally store temp elements from k = 0 , k<ei-si+1  to i = si to i = ei in v

}

</details>

#### [Intersection in 2 sorted Arrays](Sortings/Intersection2SortedArr.cpp)
<details>
<summary>Hint</summary>
{
  
   As we do in merge funcn 2 pointers approach we will print v1[i] == v2[j] holds o/w inc smaller values itr by 1

   To avoid duplicated we can add if(i>0 && v1[i] == v1[i-1])skipp means i++

   
}

</details>

#### [Union of 2 Sorted Arrays](Sortings/UnionOf2Arr.cpp)
<details>
<summary>Hint</summary>
{
    Same as intersection but we will avoid intersections from both v1 and v2
    Also we have to add remaining elements if any and add them without there duplicates
    
}

</details>

