#include <vector>
#include <algorithm>
class solution {
    public:
    /*
    *    Given a sorted array nums, remove the duplicates in-place such that each element 
    *   appear only once and return the new length.Do not allocate extra space for another array, 
    *   you must do this by modifying the input array in-place with O(1) extra memory.
    */
    int remove_duplicates(std::vector<int> &arr){
        int length = 1; 
        int prev = arr[0]; 
        for(int i = 1; i < arr.size(); i++){
            if(arr[i]!=prev){
                arr[length++] = arr[i]; 
                prev = arr[i]; 
            }
        }
        return length; 
    }

    int remove_duplicates_2(std::vector<int> &arr){
        std::sort(arr.begin(), arr.end()); 
        arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
        return arr.size();  
    }
};