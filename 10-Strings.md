# Strings

**Strings are the sequence of characters** <br>
>Why? number of characters are limited <br>
Advantage: Have contiguous values from 'a' to 'z'  or 'A' to 'Z'<br>
C++ stores acc to ASCII value 97 for 'a' and 65 for 'A'  48 for '0' and 0 for '\0'<br>

>Difference between char[] and strings<br>
strings are always terminated with a '\0' character and char array may or may not<br>


### [Famous Functions](codes/Strings/FamousFuctions.cpp)
 - str.size() OR str.length() returns size of the sting
 - substr(idx,length)  pass starting idx value and length of substring you want
 - find(str1,str2) checks weather str2 is present in str1 or not (Returns a valid idx if present)
 - str.erase(idx,length) erase character from the string from starting idx to given length
 - tolower(char &ch)  toupper(char &ch)  can be used like for(auto &ch : str){tolower(ch)};
 - sort aur reverse to hai hi stl wale

<br>

---
### Problems & Codes
---


#### [Print Freq in Sorted Order]()
<details>
<summary>Hint</summary>

    
    Naive sol: O(Nsq) two loops count indvidual frequencies of every char
    O(N): maintain a count arr[26] = {0} for char 'a' to 'z' 
    and traverse string and do count[str[i]-'a']++; to increase the count of freq
    print from count array as char = i+'a'  and freq = count[i];



</details>




#### [Is Subsequence Present In A Given String](codes/Strings/IsSubseqPresent.cpp)
<details>
<summary>Hint</summary>

    
    Subsequence ka matlab kuch characters agar hata de strings se fir string ko same order me read kre
    //Direct Method s1.find(s2) agar return kare idx from 0 to s1.size()-1 to YES o/w NO

    //Iterative 
    //Two Pointers i = 0; j = 0;
    increment both i and j if s1[i] == s2[j] 
        else increment only i    until i<s1.size() && j < s2.size()

        At last check if(j == s2.size()) aur not if yes print "YES" o/w "NO"
    
    //Same thing can be done through rcrsn f(s1,s2,n1,n2)   
        //base case if (n2 == 0) return true;  if(n1 == 0) return false; 
        like return (s1[n1-1] == s2[n2-1])? f(s1,s2,n1-1,n2-1) : f(s1,s2,n1-1,n2);






</details>




#### [IsPalindrome](codes/Strings/IsPalindrome.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol reverse and check if s1 == s2 or not

    Two iterator solution si = 0; ei = n-1
    while(si<ei){
        if(str[si] != str[ei]){
            return false;
        }
        si++;
        ei--;
    }

    Same can be done through rcrsn as f(str,si,ei)
    base case si>ei return true;
    return str[si] == str[ei] && f(str,si+1,ei-1)



</details>




#### [Check of Anagram/IsPermutation](codes/Strings/IsAnagram_Permutation.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol sort both and equate

    Optimized:
    chk freq of all ch in str1 equals freq of all chars in str2 or not
    calc freq using a 256 size array and chk do freq[str1[i]]++ and freq[str2[i]]-- chk for all 0s at last






</details>




#### [Leftmost Repeating Character](codes/Strings/LeftmostRepeatingCharacter.cpp)
<details>
<summary>Hint</summary>

    
    Output the index of leftmost character that repeats in a given string

    Naive sol O(Nsq) break loop instantly if we found a repeating character

    Optimized:
        Using Aux Space: map<ch,ll> first val stores char and second stores leftmost idx of that char
        as soon as char is already present in array we update aur res as min(res,map.second)

        Another without using map

        2-Traversal of string
        Maintain a frequency arr and count frequencies
        Traverse string again and check for char with freq greater than 1


        More Optimized 1-Traversal + constant traversal of freq i.e.256 at max
        traverse string from right to left and take ans = -1
        //maintain a boolean visited array for  each char if(it is visited)set ans = i;



</details>




#### [Leftmost Non-Repeating Charater](codes/Strings/LeftmostNonRepChar.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol O(Nsq) two loops

    2 Traversal
    1st traversal: Frequency array
    2nd traversal: if(freq[str[i]]) == 1 print idx

    1 Traversal + const traversal sol

    Create a firstIdx array with all entries -1
    store firstIdx at very first occ of char 
    if firstIdx[str[i]] != -1 and char repeats make it -2

    NOW traverse firstIdx array ans = min(ans,firstIdx[str[i]]) if it is not -1 and -2





</details>




#### [Reverse Words In A Given String](codes/Strings/ReverseWordsInAnString.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol : Maintain a stack of words and print them

    Reverse whole string 
    then reverse each words again
    take care of corner condition i.e. for first word



</details>




#### [Naive Pattern Searching In Given String](codes/Strings/NaivePatternSearching.cpp)
<details>
<summary>Hint</summary>

    Har window ke liye chk kro kya wo pattern se match krta hai kya 
    agar sare distincts char hai pattern me to TC  O(N)
    repeated bhi hai to TC O((N-M+1)*M)
    Sare index print krte jao jaha bhi pattern complete hua uska i-m+1 th idx
    


</details>




#### [Rabin Karp Algo For Pattern Searching (Rolling Hash Technique)](codes/Strings/RabinKarpPatternSearching.cpp)
<details>
<summary>Hint</summary>

    
    It uses rolling hash teqnique basically we compute hash func for first window of str and pattern

    for every window we check if hash value matches we will compare for that window only

    we will calculate hash value for every next window using previous windows

    we can choose weighted sum as a hash function and taking%m to avoid overflows m shlould  be big and prime



</details>




#### [Constructing Longest Prefix Suffix array](codes/Strings/LongestProperPerfixSuffixArray.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol : O(N cube)
    we will fill lps array using longPropPreSuff(str,i+1)  for i = 0 to n

    longPropPreSuff(str,n) what will it do 
    it will check for len = n-1 to len = 1 whenever prefix = suffix 
        i.e. all str[i] = str[n-len+i] where i ranges from 0 to len-1
        return len
    
    otherwise return 0

    Efficient Solution O(N): atmost 2n 
    //we will compute lps[i] using len and lps[0] to lps[i-1]

    //lps[0] = 0 always

    ll i = 1, len = 0;

    while(i < n){
        if(str[i] == str[len]){
            len++; lps[i] = len; i++;
        }
        else{
            if(len == 0){
                lps[i] = 0; i++;
            }
            else{
                len = lps[i-1];
            }
            //we are not incrementing i here and checking for valid len from previous lps values
        }
    }




</details>




#### [KMP Algo For Pattern Searching](codes/Strings/KMP_PatternSearching_LPS.cpp)
<details>
<summary>Hint</summary>

    
    we will use above method to precompute lps array of pattern 
    now we will check for every window and shift pattern accordingly

    ll i = 0, j = 0;
    while(i < n){
        if(str[i] == pattern[j]){
            i++; j++;
        }
        if(j == m){
            print(i-m) and set j = lps[m-1];
            //we will chk for next window and had set j accordingly to shift pattern
        }
        else if(i < n && pattern[j] != str[i]){
            if(j == 0)i++;
            else j = lps[j-1]; again we shifted pattern
        }
    }



</details>





#### [Check If Strings Are Rotated](codes/Strings/IsRotated.cpp)
<details>
<summary>Hint</summary>

    Naive O(Nsq) solution check all roatations of s1 possible one by one at any point if s1 equals s2 return true

    Optimized: (O(N)*const) Can use % operator to find presence of s2 in s1 but we have another badhiya option
    concatenate s1 with itself i.e. s1 += s1;
    now using stl find funcn if s1.find(s2) return a valid idx from 0 to 2n return yes o/w no


</details>


#### [Anagram Search For Given Pattern In Given String](codes/Strings/IsPatternPresentInAnyAnagram.cpp)
<details>
<summary>Hint</summary>

    Naive sol for every anagram(permutation of pattern) chk its presence in str O(Fact(m)* m)

    
    take two freq arrays of const size i.e.256 
    compute freq of pattern in arr1 and first window in arr 2
    for every next window compute freq using prev window
    at any point if to freq arrays equals return true

    At last if no match found return false;


</details>


#### [Lexographic Rank Calculation For Given String](codes/Strings/LexographicRankOfGivenString.cpp)
<details>
<summary>Hint</summary>

    NAIVE Solution Check Its Rank in all of its permutation possible in lexo order
    //Suppose we have only distinct chars in string
    //we can maintain a count array to find number of lexo smaller chars present in right side of curr

    to do this we maintain a count/freq array then we take prefix of this
    take prefix sum of count into count
    initialize res by 1
    to get required count we take count[str[i]-1] 
    and we have a multiplier mul starting from n-1 to 1 factorial respectively
    at this time we will add mul*count[str[i]-1]
    then we remove curr leftmost char from count arr
    how? by dec freq for all char j = count[str[i]] to j < 256  by 1

    at last return res
    
    

</details>


#### [Return Length Of Longest Substring With All Distinct Characters](codes/Strings/LengthOfLongestSubstringWithUniqueChars.cpp)
<details>
<summary>Hint</summary>

    O(Ncube) For all possible substrings take maxeln for substring having all characters distinct

    O(Nsq) Improved naive sol here we will maintain a visited for every char starting with i for uniqueness

    O(N) we will take maxlen for characters in the following way:
        eg:      a b c a d b d
        maxEnd:  1 2 3 3 4 4 2

        we will take max of maxEnd as ans

        to calc maxEnd we need a prevIdx array init with -1 as all entries 
            which will give the prev rightmost occurance for curr char
        as we see a char we will set prevIdx[str[j]] = j
        to calc length we use j-i+1  //where j is for curr end and i = max(i,prev[str[j]]+1)

    
        return ans

</details>




