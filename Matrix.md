## CODES


#### [Rotate Matrix AntiClockWise By 90deg](Matrix/RotateAntiClockBy90DEG.cpp)
<details>
<summary>Hint</summary>
{
  
    FIrst transpose then swap all columns and get required matrix
    

}

</details>


#### [Spiral Matrix](Matrix/SpiralMatrix.cpp)
<details>
<summary>Hint</summary>
{
  
    //Take care if only 1 row or 1 column matrix

    //Print top right bottom then left
    

}

</details>


#### [MedianIn2DArray](Matrix/MedianIn2DArrays.cpp)
Row-Wise Sorted
<details>
<summary>Hint</summary>
{

    Naive : create 1D array sort it and find median
  
    //Median position = (r*c+1)/2;

    calc mini and maxi

    like binary search calc mid and 
    every time calc midPos by sum of  upperbound of mid in every row to know no of exactly equal or lesser elements in matrix

    move left and right accordingly


    
    

}

</details>