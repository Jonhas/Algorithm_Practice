#include<vector>
#include <algorithm>
class solution{
    public:
    /*  
    * Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    */
    void moveZeros(std::vector<int> &nums){
        int j = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]!=0) nums[j++] = nums[i]; 
        }
        for(;j<nums.size(); j++) nums[j] = 0; 
    }

    void move_zeros(std::vector<int> &nums){
        int c = std::count(nums.begin(), nums.end(), 0); 
        nums.erase(std::remove(nums.begin(), nums.end(), 0)); 
        for(int i = 0; i < c; i++ ) nums.push_back(0); 
    }
}; 