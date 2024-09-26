# Searching And Binary Search 

## Sorted Array Bole To Binary Search TC O(logn)

### Think binSearch when ans lies in a range and we can ignore a part of range using some conditions

### Codes And Hacks

#### [Binary Search Rec And Iterative Both](codes/Searching/BinarySearch.cpp)
<details>
<summary>Hint</summary>

    
    Take n,si,ei as a parameter and check if mid element is equal to key if yes return mid 
    else if midval > key search in left part o/w search in right half 
    don't forget to update mid 

</details>

#### [First/Last Occ in Sorted Array Or Count Of A Element](codes/Searching/FirstNLastOccIndexBinSearch.cpp)
<details>
<summary>Hint</summary>

    Instead of using while store ans and search for left for left most occ and right for rightmost
    //Take care of corner cases for eg: idx = 0 for leftmost and n-1 for rightmost
    count = r-l+1;

</details>

#### [Search In An Infinite Sorted Array](codes/Searching/Search_InfiniteArray.cpp)
<details>
<summary>Hint</summary>
    Seprately check for 0th idx and then take mid = 1 and use condition of sorting 
    if v[mid] == key return mid;
    if v[mid] < key then i*=2; 
    else v[mid] > key search between mid/2+1 to mid-1 

    nhi mila to -1 return karne kaa
</details>

#### [Find SqRoot Floor value](codes/Searching/SqRootFloorValue.cpp)
<details>
<summary>Hint</summary>

    agar mid*mid > n to left me 
    agar mid*mid < n hai to pahle ans store kr lo fir right me search kro
</details>

#### [IMP: Search In Sorted And Rotated Array](codes/Searching/Search_SortedRotatedArray.cpp)
<details>
<summary>Hint</summary>
    Graph se socho corner elements ka use kr skte hai

    //Left part sorted hoga agar v[mid]>=key hai aur v[si]<=key
    else right ke liye rec call kr skte hai


</details>

#### [Find Peak Element Greater than Neighbours](codes/Searching/PeakElementGreaterThanNeighbours.cpp)
<details>
<summary>Hint</summary>

    Corner conditions v[0]>v[1] return v[0]; Similarly if v[n-2]< v[n-1] return v[n-1];
    Now if v[mid]>= v[mid-1] && v[mid]>=v[mid+1] return mid;
    // dono chote nahi hai mtlb ek to bada hai
    else if v[mid-1] > v[mid] 100 % left part contains a peak
    else right me


</details>

#### [Two Pointer PairSum = Given Sum In Sorted Array](codes/Searching/TwoPointerPairSumInSorted.cpp)
<details>
<summary>Hint</summary>

    chk if sum is less lft ptr++; else right ptr--  while(leftptr < rightptr)
</details>

#### [Triplet Sum In Sorted Array Equal To Given Sum](codes/Searching/PairOfThreeEqualsGivenSum.cpp)
<details>
<summary>Hint</summary>

    Fix i = 0 to < n-2 
    find two pair sum by two pointer approach for every left idx i+1 to last for sum = s-v[i] k liye do ki pair
</details>

#### [Imp: Median Of Two Sorted And Merged Array ](codes/Searching/MedianOf2SortedArr.cpp)
<details>
<summary>Hint</summary>

    Merge wale concept se to ho jayega pr O(log(n1)) me socho


    Binary Search ka concept aise lagega ki <br>

    ....,max1,min1,.....            //i = (si+ei)/2  -->ei ko phle n lenge 

    ...........,max2,min2,......

    if(max1 <= min2 && max2 <= min1){
        n1+n2 even to return double max of two + min of two div by 2
        odd ho to max of two ka double return kr do
    }
    else if(max1 > min2){
        ei = i-1;
    }
    else{
        si = i+1;
    }


</details>

#### [RepeatingElement_ArrayConsistSingleRepeatingElement](codes/Searching/RepeatingElement.cpp)
<details>
<summary>Hint</summary>
<br>
 
    Problem: All elements from 0 to max are present exactly once except repeated

    if(retpeated is even no of times) xor arr with 0 to max and get final ans
    else 
    sort array and chk if v[i] != i and print the ans
 
</details>

#### [RepeatedElementOptimizedBySumAndChainMethod](codes/Searching/RepeatingElementOptimizedWithChain.cpp)
<details>
<summary>Hint</summary>
<br>
 
    Problem: All elements from 0 to max are present exactly once except repeated

    Solution 1 we can use arrsum, 0toMaxi Sum, n-maxi to count freq of rep ele 

    Solution 2 When Smallest Element is 1 : As we do in linked list first detect loop then put slow at 0th idx then inc both slow fast by 1
    first assign v[0] to both slow and fast
    
    then inc slow = v[slow] & fast = v[v[fast]];

    once they meet we will detect loop then put slow = v[0] again

    now increment slow = v[slow] and fast = v[fast] with same speed
    They will meet at repeated point and return slow if mini = 1 
    
    agar 0 bhi hota to sabme add 1 kr dete last me slow-1 return kr dete



</details>


#### [Book Allocation MinNoOfConsecutivePagesToEachStudent](codes/Searching/BookAllocationMinPages.cpp)
<details>
<summary>Hint</summary>
<br>
 
    Ans lies in a range and we can say that if mid is ans then there is a chance for left otherwise find ans in right we will apply bin search and to chk mid is ans or not we will make isPossible funcn

    It will take v,mid,k as parameters where k = no of students
    we will distribut currsum pages and inc stud count until currsum<=mid
    then we will return true or false accordingly using studct<=k 


</details>


