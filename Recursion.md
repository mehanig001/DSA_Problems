## Short notes on Recursion


Recursion means function calling itself maybe directly or indirectly <bt>

Kab use karte hai? <br>
jab koi task given ho aur agar uske subtask ka solution hame pata ho to uska use karke how can we get the result of bigger task.
<br>
Seedhi bhasha me f(n) ki value kya pata laga sakte hai agar f(n-1) ki pata hai to.

### Structure
Fun(int n){

    //Base Case

    //Some Work

    //Recursive call

}

<br>

Tailing recursion means hame stack maintain karne ki jarrorat nahi ham directly wo kaam kar sakte hai 
<br>
Example : Fun printing from n to 1 (isme ham n print karne ke baad rec fun call krte hai isse hame wait nhi krna padta)

<br>
Tailing recursion thoda sa faster hota hai as compared to non tailing For Examples: <br>
1. Quick Sort than Merge Sort <br>
2. Pre and In Order Traversal than Post<br>

<br><br>

### Time Complexity calc
find rec relation <br>
like for fibo(n) = fibo(n-1) + fibo(n-2) <br>
T(n) = T(n-1) + T(n-2) + c <br>
Make complete bin tree asumming constant part as roots and extend it further <br>
observe pattern and write value for some of c until base case reaches<br><br><br>



### Codes And Problems

#### print n to 1
#### print 1 to n and equivalent tail rec 
Hint: fun(int n, int i); i for directly printing
#### Fibonacci
Hint: f(n) = f(n-1)+f(n-2);
#### Sum up to first n
Hint: n + sum(n-1);
#### Rope Cutting Problem
I/P n,a,b,c <br>
O/P No of max peices in which we can cut a rope of initial length n such that remaining ropes length lies in {a,b,c} <br>
Hint: Base Case n==0 return 0; And n<0 return -1;<br>
        ways(n,a,b,c) will call
        res = max of the three ways (n-a,a,b,c), (n-b,a,b,c) and (n-c,a,b,c) <br>
        if all will return -1 then cuts are invalid simply return -1;<br>
        return 1 + res;
#### Subsets
Return power set of given string example "abc" <br>
Hint:Two rec calls for subset(str,newstr,i)<br>
        First: subset(str,newstr,i+1);
        Second: subset(str,newstr+str[i],i+1)

#### Tower Of Hanoi
Hint: Fun is(n,src,hlp,dst)<br>
        BaseCase: if(n == 1) print src to dst<br><br>

Two rec call <br>
        First: first move from src to hlp using dst<br>
        Between this print src to dst;<br>
        Second: move from hlp to dst using src<br>

        T(n) = 2T(n-1) + c

#### Josephus Problem (last man standing)
n people arrange in a circle and at every itr kth people will be killed <br>
Hint: Sol for 0 based indexing think if chote part ka soln pata hai to bade part ka kaise nikale <br>
        //BaseCase If n == 1 matlab ek hi hai 0 wala 
        F(n,k) = [F(n-1)+k]%n <br>

#### No of Subset equal to given sum
Hint: Alag Alag subset banaane se accha ek su, variable leke chalo
f(v,k,i,sum) will call with ctr = sum + sum+v[i]
//BaseCase when i == v.size() return sum == k?1:0;
#### Permutaions of String 
Halke me mat lena bawa <br>
Age wale ko fix krte jo bache honge unhe permute fun sambhal lega <br>
rec function k andar loop bhi hoga <br>
f(str,i){
    if(i == str.size()-1) print str return;

    for(j = i to str.size()){
        swap(str[i],str[j])
        permute(str,i+1)
        swap(str[i],str[j])
    }
}
isko samajh dalaa to life jhingalalaa
