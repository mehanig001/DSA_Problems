# Stacks
---
**LIFO LAST IN FIRST OUT** <br>
Basic operations: push(), pop(), empty(), top();


### Applications
 - Function Calls
 - Balanced Paranthesis
 - Reversing Items
 - Infix to Pos/Pre-fix
 - Evaluation of Post/Pre-fix
 - Stock Span Problem
 - Undo Redo in browsers
<br>

---
### Problems & Codes
---


#### [Implementation using fixed size array](Stacks/ImplementingWithFixedSizeArray.cpp)
<details>
<summary>Hint</summary>

    
    data members: int*arr, int cap, int top
    hint using const define arr = new int(n);



</details>




#### [Implementing using vector](Stacks/ImplementationUsingVector.cpp)
<details>
<summary>Hint</summary>

    
    data member vector<ll> v only 

</details>




#### [Implementing using LinkedList](Stacks/ImplentationUsingLinkedList.cpp)
<details>
<summary>Hint</summary>

    
    First create class Node

    data member Node* head, int size;
    constructor: head = NUll , size = 0;



</details>




#### [Balanced Paranthesis](Stacks/BalancedParanthesis.cpp)
<details>
<summary>Hint</summary>

    push opening brackets into the stack

    whenever we found a closing bracket we chk  if st.top() char is matched opening or not if no or stack is empty return no else st.pop()


</details>




#### [Implementing 2 Stacks Using An Array](Stacks/TwoStacksUsingSingleArray.cpp)
<details>
<summary>Hint</summary>


    Naive sol Divide in two halfs for stack1 and stack2
    Drawback: space is not utilized optimally

    Optimized:
    top1 = -1 and top2 = n;
    now pushing element in first idx chk for top1 + 1 < top2 and  do top1++ and insert at top1 
    similarly for stack2 do top2-- if space available





</details>




#### [Implementing K Stacks Using Array](Stacks/NStacksUsingSingleArray.cpp)
<details>
<summary>Hint</summary>

    
    Naive sol O(Nsq) divide arr in n/k sub groups for stacks
    Problem: space is not utilized optimally

    Efficient:
    data members: int*arr, int*top, int* next, int k, free_top,cap

    we made two extra arrays
    first next array when the stack would empty next array is pointing to the next free idx available in array
    and when stack has some element next array will start pointing idx of prev element stored in nth stack






    Constructor KStacks(int k,n){
        free_top = 0 //first free idx is 0
        cap = n
        this->k = k

        arr = new int(n)
        next = new int(n)
        top = new int(k,-1);
        
        for(int i = 1; i < n; i++){
            next[i] = i+1
        }
        next[n-1] = -1
    }

    push(int sn, int x){

        i = free_top
        free_top  = next[i]
        next[i] = top[sn]
        top[sn] = i

        arr[i]=x
    }

    pop(int sn){
        i = top[sn]
        top[sn] = next[i]
        next[i] = free_top
        free_top = i
        
        //return arr[i]
    }





</details>




#### [Stock Span Problem -> Closest Prev Greater Element](Stacks/StockSpanProblem_ClosestPrevGreaterElement.cpp)
<details>
<summary>Hint</summary>

    the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than its price on the given day. 

    I/P
    60 10 20 15 35 50
    O/P
    1  1  2  1  4  5

    Naive TC O(Nsq)

    create an stack and push first elements idx i.e. 0 
    print 1 for idx 0

    for i = 1 to i< n; i++
        //aage ane wale element ke liye curr element se chote ya baraabar useful nahi hai
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop()
        }
        span = st.empty() ? i+1 : i-st.top();
        print(span)

        st.push(i)
    
    //end of for loop




</details>




#### [Prev Greater Element](Stacks/PrevGreaterElement_Closest.cpp)
<details>
<summary>Hint</summary>

    I/P  15  10  18  12  4   6   2   8
    O/P -1   15  -1  1   12  12  6  12

    lets return a vector<int> ans of elements which are closest prev greater than curr

    initialize with stack st and push 0 intially
    ans.push_back(-1)

    for(i = 1; i < n; i++){
        while(!st.empty() && v[st.top()] <= v[i]){st.pop();}

        if(st.empty())ans.push_back(-1);
        else ans.push_back(v[st.top()])
    }

    return ans


</details>




#### [Next Greater Element](Stacks/NextGreaterElementClosest.cpp)
<details>
<summary>Hint</summary>

    I/P  15  10  18  12  4   6   2   8
    O/P  18  18  -1  -1  6   8   8  -1

    lets return a vector<int> ans of elements which are closest prev greater than curr

    initialize with stack st and push n-1 intially
    ans.push_back(-1)

    for(i = n-2; i >= 0; i--){
        while(!st.empty() && v[st.top()] <= v[i]){st.pop();}

        if(st.empty())ans.push_back(-1);
        else ans.push_back(v[st.top()])
    }

    reverse(ans.begin(),ans.end())

    return ans
    



</details>




#### [Largest Rectangular Area In Histogram](Stacks/LargestRectangularArea.cpp)
<details>
<summary>Hint</summary>

    I/P:   6   2   5   4   1   5   6

    pre:  -1  -1   1   1  -1   4   5
    nxt:   1   4   3   4   7   7   7

    O/P: 10

    
    Naive sol : O(N sq) for every i traverse j = i-1 to 0 and i+1 to n to find just smaller

    Better: O(N) solution but req 3 traversal and extra space for calc prev smaller and greater element

        step1 initialize res = 0
        step2 calc prevsmaller arr and next smaller arr
        step3 Do following for every ith element
        
            curr = arr[i]
            curr += (i-pre[i]-1)*arr[i]
            curr += (nxt[i]-i-1)*arr[i]

            res = max(res,curr)

        step4 return res


    Efficient: Req 1 Traversal and Only Aux space for 1 stack

    we are maintaining stack of indexes in such a way that upar wale idx pe jo element ayega wo jyada hona chahiye
    agar koi chota element ata hai to kuch compute krenge aur res ko max le lenge
    last me bache hue idx jo stack me hai unko process kr lenge

    stack<int>st;
    res = 0

    for(i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            tp = st.pop()
            curr = arr[tp]*(st.empty()? i :(i-st.top()-1))
            res max(res,curr)
        }
        st.push(i);
    }

    while(!st.pop()){
        tp = st.pop()
        curr = arr[tp]*(st.empty() ? n : (n-st.top()-))
        res = max(res,curr)
    }


    return res

</details>





#### [Largest Rectangle with all 1s](Stacks/LargestRectangleWithALL1s2Darr.cpp)
<details>
<summary>Hint</summary>

    Naive O(Row cube * Col cube):
        consider every element as topleft corner of rectange and calc all size rectangles possible with all 1s
    
    Efficient using prev problem largest area of histogram

    first calc for first row 
    ll res = largestHist(v[0],col)

    for(i = 1; i < row; i++){
        for(j = 0; j < col; j++){
            if(v[i][j] == 1){
                v[i][j] += v[i-1][j] //we are increasing height of histogram accordingly when we see a 1
            }
        }
        res = max(res, largesHist(v[i],c))

    }

    return res


</details>


#### [GetMin Function Implementation](Stacks/GetMin.cpp)
<details>
<summary>Hint</summary>

    
        implement with vector and every time calc min 
        Implement an aux stack for storing all min values min


    
    Efficient Assuming All positive values to be stored

    we push first element as a min and whenever we find an element greater than min we simply push that into the stack
    if we found and element less than min 
    we push a negative val to stack as x-min and update min to x
    (to retain previous min we can do min-x  where x is top element in peek and pop operations)


    For storing negative values also what we can do is 
    in push we do 2*x-min if x < min
    peek t<min ? min : t
    pop if(top<min) res = min and min = 2*min-top



    


</details>


#### [Infix To Postfix](Stacks/InfixToPostfix.cpp)
<details>
<summary>Hint</summary>

    Naive Add Parenthesis according to the pecedence and associativity and then start converting infix to postfix from innermost parenthesis to the outermost and remove parenthesis

    Efficient using stack st of operators
    create an empty stack and res = "";

    for every ch in str 
    if ch is operand res+=ch
    else 
        if ch is '(' push ch in stack st
        if ch is ')' pop items from stack and append to res until we found corresponding opening
        else + - * / ^
            if(precedence of top < precedence of ch) st.push(ch)
            else  jab tak usse kam precedence ka top na mile pop krke res me append krte jao last me ch push kr dena
            equal ke liye associativity use krna jaise agar *,/ or +,- hai to higher wala lagega ki lower precedence wala
            

    
    last me append remaining stack elements to the res



</details>


#### [Infix To Prefix](Stacks/InfixToPrefix.cpp)
<details>
<summary>Hint</summary>


    same as infix to postfix only we have to change the following
    traverse ch in str from right to left
    if closing brack push and if opening pop until closing found and append it to the res string

    +-*/ walo ke liye same as infix to postfix precedence wise decide krenge aur operands ko simply res me append

    last me jo res ayega uska reverse krke return krna hai




</details>


#### [Evaluate Postfix](Stacks/EvaluateProstfix.cpp)
<details>
<summary>Hint</summary>

    This time we are going to create a stack of operand 
    whenever we find a operator we will calc op2 pop and op1 pop
    then we calc val as op1(op)op2
    push val to stack


    At last return st.top()



</details>


#### [Evaluate Prefix](Stacks/EvaluatePrefix.cpp)
<details>
<summary>Hint</summary>

    
    traverse the str from reight to left and do the same as in eval of postfix
    
    This time we are going to create a stack of operand 
    whenever we find a operator we will calc op2 pop and op1 pop
    then we calc val as op1(op)op2
    push val to stack


    At last return st.top()

</details>



