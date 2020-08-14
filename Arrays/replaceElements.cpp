#include <iostream>
#include <vector>
class solution {
    /*
    * Given an array arr, replace every element in that array with the greatest element 
    * among the elements to its right, and replace the last element with -1
    */
    public:
    std::vector<int> replace_element(std::vector<int> &arr){
      int current_max = -1; 
      for(int i = arr.size()-1; i >= 0; i--)  {
          int temp = arr[i]; 
          arr[i] = current_max; 
          current_max = std::max(arr[i], temp); 
      }
      return std::move(arr); 
    }
}; 