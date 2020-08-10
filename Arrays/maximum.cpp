#include <iostream>
#include <vector>
#include <algorithm>
/*
* Given a non-empty array of integers, return the third maximum numbers in this array. If it does not 
* exist, return the maximum number. The time complexity must be O(N). 
*/
int third_max(std::vector<int> &v){
    //pointers for keeping track of the first, second, and third maximum value within our array 
    int max = 0, second_max = 0, third_max = 0; 
    //Iterate throughout the array to make updates and comparisons. 
    for(auto i : v){
      if (i == max || i == second_max || i == third_max) continue; 
      if(i > max) {
          //Whenever we change the value of max, the second max then becomes the aforementioned max, and the third max becomes the prior second_max. 
          //Therefore, we need to assign the references before we change the value of max. 
          third_max = second_max; 
          second_max = max; 
          max = i;
      } 
      else if (i > second_max){
          //If we get a second max, then the third_max becomes the prior second max and then we update the second max 
          third_max = second_max; 
          second_max = i; 
      }
      //Simply assign the third_max. 
      else if(i > third_max) third_max = i; 
    }
    if(third_max == 0) return max; 
    return third_max; 
}
//Another way of finding the third max number using the built in sort function in the algorithm header 
int thirdd_max(std::vector<int> &v){
    std::sort(v.begin(), v.end()); 
    return v[v.size()-3]; 
}

/*
int main(int argc, char** argv){
    std::vector<int> v = {5,3,2,1,9,6,15,26}; 
    int third_maximum = third_max(v); 
    int third = thirdd_max(v); 
    std::cout<< third_maximum << '\n'; 
    std::cout << third << '\n'; 
    return 0; 
}
*/
