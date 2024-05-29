# Tree (Non Linear DS)


Basic variations: 
Trie, SuffixTree, BinaryIdxTree, SegmentTree, AVL <br>
Basic Terms:
node, root, leaf, child, parent, subtree, descendents, ancestor, degree, internal <br>


### Applications
 - To represent heirarchial data structures
 - Organisation structure
 - Folder Structure
 - XML/HTML content
 - OOPs(Inheritance)


<br>


Binary Tree: Atmost two children <br>
Complete Tree: All levels are completely filled except possibly the last level. <br>
Full Binary Tree: Every node has either 0 or 2 child nodes. <br>
Perfect Binary Tree: All internal nodes have two children, and all leaf nodes are at the same level. <br>

---
### Problems & Codes
---


#### [Implementation And DepthFirstTraversal](Tree/DephtFirstTraversal.cpp)
<details>
<summary>Hint</summary>

    
    struct Node{
        int data;
        Node* left
        Node* right

        Node(){
            data = 0;
            left = right = NULL;
        }

    };



    preOrder: root left right
    inOrder: left root right
    postOrder: left right root



</details>

#### [Hieght Of A Binary Tree](Tree/HeightOfBinTree.cpp)
<details>
<summary>Hint</summary>

    1+max(hieght of left subtree, height of rightsubtree) using recursion
    if(root == NULL)return 0;


</details>

#### [Level Order Traversal](Tree/LevelOrderTraversal.cpp)
<details>
<summary>Hint</summary>

    
    TC O(N)  AS->O(w) width of tree
    Use Queue data structure 
    queue ki current size current level ke no of elements bata degi uska use krke 
    utne elements ko pop(print) krke unke childs ko queue me daal do jab tak queue khali n ho jaye



</details>


# [Strivers A2Z Sheet](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2)





