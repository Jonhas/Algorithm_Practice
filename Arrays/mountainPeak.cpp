#include <vector>
#include <iostream>
/*
* Given an array A of integers, return true if and only if it is a valid mountain array.
* Recall that A is a mountain array if and only if:
*   A.length >=3 
*   There exists some i with 0 < i < A.length-1 such that:
*       A[0] < A[1] < ... < A[i-1] < A[i]       (ascending)
*       A[i] > A[i+1] > ... > A[A.length-1]     (descending)
*/
class Solution {
public:
    bool validMountainArray(std::vector<int>& A) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        if(A.size() < 3) return false; 
        int pointer =1; 
        
        //Begin to ascend until we hit the peak 
        while(pointer < A.size()){
            if(A[pointer-1] < A[pointer]) pointer++; 
            else break; 
        }//have stopped descending here 
        
        //If we continue to ascend without any descendance and we have reached the end of the list 
        if(pointer == A.size() || pointer ==1) return false; 
        
        //Begin to descend until we hit ground level 
        while(pointer < A.size()){
            if(A[pointer-1] > A[pointer]) pointer++; 
            else break; 
        }
        
        if(pointer == A.size()) return true; 
        return false; 
    }
};