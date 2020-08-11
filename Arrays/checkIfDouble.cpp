#include <iostream>
#include <unordered_set>
#include <vector>
/*
* Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).
* More formally: 
*   i!=j 
*   0 <= i, j < arr.length 
*   arr[i] == 2*arr[j]
*/
class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {   
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL); 

        std::unordered_set<int> check; 
        //We want to check for each element within the array whether its double is located within the set. 
        //We know a double exists if x*2 = double or if x is even, double/2 = x. We use these to check if some double
        //does exist. 
        for(int x: arr){
            if(check.find(x*2)!=check.end() || (x%2==0 && check.find(x/2)!=check.end()))
                return true; 
            check.insert(x);
        }
        return false; 
    }
};