# Arrays

continguous memory allocation <br>
fast random access arr[i]<br>

### Vectors(dynamic size arrays)

Have rich librarys like sort,rev,find,max_element,accumulate,size<br>
we can get size inside function<br>
can be returned from a function<br>
copy v1 = v2 <br>

---


### Basic Problems
--- 
#### Searching in unsorted and sorted array
#### Inserting an element in between 
#### Deleting an element from array
#### [Second Largest](Array/SecondLargest.cpp)<br>

<details>
<summary>Hint</summary>

    max1=-1 aur max2=-1 dono leke chalenge aur khel hoga last element pr jaise ki max2 abhi bhi -1 ho ya max1 se chota ho pr max2 se bada ho to usko bhi consider karna hai

</details>

#### Reverse An Array

#### [Remove Duplicates](Array/RemoveDupli.cpp) 

#### [Move Zeroes To End](Array/MoveZeroesToLast.cpp)
<details>
<summary>Hint</summary>

    Simply add non zero and at last till n add 0s
</details>

#### [LeftRotateBy1](Array/LeftRotateBy1.cpp)

#### [Left Rotate By K](Array/LeftRotateByK.cpp)
<details>
<summary>Hint</summary>

    pahle left part ko rev karo
    fir right part ko
    fir pure ko

</details>

#### [LeaderInArray](Array/LeadersInArray.cpp)
    Matlb right me use bada koi n ho
#### [FreqInSortedArray](Array/FreqInSortedArr.cpp)
#### [StockByAndSell](Array/StockBuyAndSell.cpp)
<details>
<summary>Hint</summary>

    Graph ko socho jab upar badhega tab hi to profit hoga nahi to ignore
</details>

#### [Maximum Consecutive 1s in Binary Array](Array/MaxCons1sBinArray.cpp)

#### [MaxSumSubarray](Array/MaxSumSubarray.cpp)
<details>
<summary>Hint</summary>

    current element ke liye jo peeche tak ka sum aya hai wo add krna shi hai ki nhi wo chk kro aur fir maxsum le lo
</details>

#### [MaxLength of Consecutive even-odd elements](Array/MaxLenOddEvenSubarray.cpp)<br>
<details>
<summary>Hint</summary>

    both even ya odd ho to count ko fir se initialize kr do
</details>

#### [Maximum Sum in Circular Subbaray](Array/MaxCircularSubArraySum.cpp)<br>
<details>
<summary>Hint</summary>

    normal maxsum le lo
    current element ke liye jo peeche tak ka sum aya hai wo add krna shi hai ki nhi wo chk kro aur fir maxsum le lo

    intial arr ka total sum le lo

    circular ke liye chk kr lo sbka sign ulta krke usme initial total sum add kr do kyuki circular me ham wo subset hata denge jo initial total sum ko kam kar raha tha 

    dono ka max le lo 

agar sare element neg honge to normal wala hi lena
</details>

#### [Index of Majority Element Appearing more than n/2 times](Array/MaxOccElement.cpp)
<details>
<summary>Hint</summary>

    //Cancellation
    first element ko max occ maan lo aur count = 1 kr do
    fir agar dusra element ata hai to count-- kr do
    agar count 0 ho jata hai to naye wale element ka index store kar do 

    ab jo idx mila chk kr lo array me us element ki occ n/2 se jyada hai ki nhi
</details>

#### [Min Grp Flips To Make All Same In BinaryArray](Array/MinGroupFlipsToMakeAllSameBinaryArray.cpp)
<details>
<summary>Hint</summary>

    ya to grpcount ka diff 0 hoga ya 1 
    to sabse pahle element hoga wo hamesha jyada ya barabar bar ayega
</details>

#### [Window Sliding Problem MaxSumOfkConsElements](Array/SlidingWindow.cpp)
<details>
<summary>Hint</summary>

    pichla hatao naya lao according to the given situation
</details>

#### [Subarray With Given Sum Exist Or Not](Array/SubarrWithSumExist.cpp)
<details>
<summary>Hint</summary>

    sliding window ki tarah remove the previous one from sum and chk if curr = given sum of not if greater then reomve until it becomes equal or smaller
    otherwise simply add
</details>


#### [Prefix Sum](Array/WieghtedPrefix.cpp)
<details>
<summary>Hint</summary>

    kuch difference lene ka socho normal prefix aur weighted prefix ko use krke
    weighted matlab 1*a[0] , 1*a[0]+2*a[1], 1*a[0]+2*a[1]+3*a[2]........
</details>


#### [Equilibrium Point Exist Or Not](Array/EquilibriumExist.cpp)
<details>
<summary>Hint</summary>

    left sum = right sum then yes
    left sum for left corner = 0 similarly for right
    calc total sum for help
</details>

#### [Find Max Appearing Element in Given Ranges From Left To Right](Array/MaxAppEleInRange.cpp)
<details>
<summary>Hint</summary>

    O(N*MAX) make freq[max] and for each j = left[i] to right[i] freq[j]++;
    Or
    O(N+MAX) f[left[i]] = 1 and f[right[i] +1]  = -1
    Now take pref sum of f and then idx of maxi will be ans
</details>



