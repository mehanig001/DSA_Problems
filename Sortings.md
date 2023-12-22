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


#### [Count Inversion](Sortings/CountInversionInArr.cpp)
<details>
<summary>Hint</summary>
{
    Use concept of merge in mergeSort

    Inversion means for an element how many smaller elements are present on right side of it

    when we are taking a right part of element before left part 
    we are getting the inversion from ith part to mid

    so increment the ans while doing this by ans += (mid-si+1) - (i+1)
    when v[j]<v[i] happens and you add v[j] to temp 


}

</details>

#### [Partition](Sortings/Partition.cpp)
<details>
<summary>Hint</summary>
{
    Partition refers that for a fixed element(pivot) in array left elements should be smaller than pivot
    and right elements should be greater 

    this can be achieved by Naive Partition in which you make a temp[]
    first traverse and store smaller elements in temp
    then again traverse and store larger elements in temp

    copy elements of temp in initial arr and get results or return i


    Else what we can do id take v[idx] as pivot and count no of smaller elements from pivot

    pvtIdx = count //correct index for pivot
    swap v[idx],v[pvtIdx]

    si = 0, ei = v.size()-1;

    while(si<ei){
        while(v[si]<pvt)si++;

        while(v[ei]>pvt)ei--;

        swap(v[si],v[ei]);
        si++;ei--;
    }

    try to have this so that lesser elements remain in left and greater in right of pivot
    

}

</details>

#### [Lumoto Partition Window Sliding Last_Pivot](Sortings/LomutoPartition_WindowSlididngAssumLastPivotAlways.cpp)
<details>
<summary>Hint</summary>
{
    take last element as pivot 

    ll i = -1;

    for(j = 0; j <= ei; j++){

        if(v[j]<pivot){
            //increase the window of smaller elements by 1
            i++;

            swap(v[i],v[j]);
        }
    }
    //take pivot to its right position
    swap(v[i+1],v[ei]);

    at last return i+1;

    //When you do Lumoto Partition it is gauranteed that pivot element will be in its correct position

}

</details>

#### [Hoare's Partition First_Pivot](Sortings/HoarePartition_FirstPivot.cpp)
<details>
<summary>Hint</summary>
{   
    Doesn't ensure that pivot will be at right position 
    Take first element as pivot and do the following


    i = si-1; j = ei+1;

    while(true){
        do{
            i++;
        }while(v[i]<pivot);

        do{
            j--;
        }while(v[i]>pivot);

        if(i>=j)return j;

        swap(v[i],v[j]);
    }

    //works faster than other partitions
    //puts smaller or equal elements on left, graeter or equal elements on right


}

</details>



#### [Quick Sort](Sortings/QuickSort.cpp)
{
    Divide & Conquer: not always divide in half
    Avg Case TC O(NlogN) Worst Case O(Nsq)
    Still considered faster due to:
    
    InPlace except recursive function call stack
    Cache friendly, Tail Recursive

    key function is partition


    qSort(v,si,ei){
        if(si>=ei){
            return; //atleast two elements required
        }

        p = partition(v,si,ei);
        qSort(v,si,p-1); //if Hoare then qSort(v,si,p)
        qSort(v,p+1,ei);
    }
    Quick Sort is not a Stable algo howevere with Naive partition it is stable but quite costly

    To avoid worst case such that array is already arranged in ascending order we can take random pivot element 

}



#### [Kth Smallest Element](Sortings/KthSmallestElement.cpp)
<details>
<summary>Hint</summary>
{
    Think of lumoto partition it ensures that smaller elements will be in left

    first approach is to sort array and return arr[k-1];

    else what we can do is applying lumoto partition in such a way as we apply binary search



    while(si<ei)
    p = partition(v,si,ei)

    if we have returned index by lumoto partition as k-1 means we reached ans

    o/w if it is > k-1 means that idx has more count of lesser numbers so move to left 
    i.e. ei = p-1;

    else si = p+1 //moved to right



}

</details>

#### [Sort 0s 1s And 2s](Sortings/Sort0s1sAnd2s.cpp)
<details>
<summary>Hint</summary>
{
    To sort 0s 1s and 2s we will keep two windows by i and mid 
    that will ensure that from 0 to i-1 0s are present
    from i to mid-1 1s are present always

    initialize i = 0, mid = 0, ei = v.size()-1;

    while(mid<=ei){

        if(v[mid] == 0){
            i++;
            mid++;
        }
        else if(v[mid] == 1){
            mid++;
        }
        else{
            swap(v[ei],v[mid]);
            ei--;
            
            //here we have not increased the mid window size of 1s because we sent 2 to the last
            //but we will process the swapped element came to mid once again
        }
    }

}

</details>
