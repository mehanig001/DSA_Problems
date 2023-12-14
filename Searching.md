# Searching And Binary Search 

## Sorted Array Bole To Binary Search TC O(logn)

### Think binSearch when ans lies in a range and we can ignore a part of range using some conditions

### Codes And Hacks

#### [Binary Search Rec And Iterative Both](Searching/BinarySearch.cpp)
<details>
<summary>Hint</summary>
<br>
Take n,si,ei as a parameter and check if mid element is equal to key if yes return mid <br>
else if midval > key search in left part o/w search in right half <br>
don't forget to update mid 
</details>

#### [First/Last Occ in Sorted Array Or Count Of A Element](Searching/FirstNLastOccIndexBinSearch.cpp)
<details>
<summary>Hint</summary>
Instead of using while store ans and search for left for left most occ and right for rightmost
//Take care of corner cases for eg: idx = 0 for leftmost and n-1 for rightmost<br>
count = r-l+1;
</details>

#### [Search In An Infinite Sorted Array](Searching/Search_InfiniteArray.cpp)
<details>
<summary>Hint</summary>
Seprately check for 0th idx and then take mid = 1 and use condition of sorting <br>
if v[mid] == key return mid;
if v[mid] < key then i*=2; 
else v[mid] > key search between mid/2+1 to mid-1 <br>

nhi mila to -1 return karne kaa<br>
</details>

#### [Find SqRoot Floor value](Searching/SqRootFloorValue.cpp)
<details>
<summary>Hint</summary>
<br>
agar mid*mid > n to left me <br>
agar mid*mid < n hai to pahle ans store kr lo fir right me search kro<br>
</details>

#### [IMP: Search In Sorted And Rotated Array](Searching/Search_SortedRotatedArray.cpp)
<details>
<summary>Hint</summary>
Graph se socho corner elements ka use kr skte hai

//Left part sorted hoga agar v[mid]>=key hai aur v[si]<=key
else right ke liye rec call kr skte hai
<br>

</details>

#### [Find Peak Element Greater than Neighbours](Searching/PeakElementGreaterThanNeighbours.cpp)
<details>
<summary>Hint</summary>
Corner conditions v[0]>v[1] return v[0]; Similarly if v[n-2]< v[n-1] return v[n-1];<br>
Now if v[mid]>= v[mid-1] && v[mid]>=v[mid+1] return mid;
// dono chote nahi hai mtlb ek to bada hai<br>
else if v[mid-1] > v[mid] 100 % left part contains a peak
else right me<br>


</details>

#### [Two Pointer PairSum = Given Sum In Sorted Array](Searching/TwoPointer.cpp)
<details>
<summary>Hint</summary>
chk if sum is less lft ptr++; else right ptr--  while(leftptr < rightptr)<br>
</details>

#### [Triplet Sum In Sorted Array Equal To Given Sum](Searching/PairOfThreeEqualsGivenSum.cpp)
<details>
<summary>Hint</summary>
Fix i = 0 to < n-2 <br>
find two pair sum by two pointer approach for every left idx i+1 to last for sum = s-v[i] k liye do ki pair<br>
</details>

#### [Imp: Median Of Two Sorted And Merged Array ](Searching/MedianOf2SortedArr.cpp)
<details>
<summary>Hint</summary>
Merge wale concept se to ho jayega pr O(log(n1)) me socho<br>

{
    Binary Search ka concept aise lagega ki <br>

    ....,max1,min1,.....            //i = (si+ei)/2  -->ei ko phle n lenge 
<br>
    ...........,max2,min2,......
<br>
    if(max1 <= min2 && max2 <= min1){
        n1+n2 even to return double max of two + min of two div by 2
        odd ho to max of two ka double return kr do<br>
    }
    else if(max1 > min2){
        ei = i-1;
    }
    else{
        si = i+1;
    }

}
