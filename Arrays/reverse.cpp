#include <iostream>
#include <vector>
/*
* Given an array A of N integers, print each elememt in reverse order as a single line of space-separated integers. 
* For optimization, we want to pass the vector by const ref. 
*/
std::vector<int> print_reverse(const std::vector<int> &v ){
   //creating a vector that will contain the contents of the reversed array
   std::vector<int> reverse; 
   //Starting at the end of the v vector, we will push the contents of the end to the beggining of the new reverse array 
   for(int i = v.size()-1; i >= 0; i--)
        reverse.push_back(v[i]); 
    //return the new reversed array of the contents of the vector that was passed. 
   return reverse; 
}

int main(int argc, char** argv)  {
    std::vector<int> v = {0,1,2,89,6,3,}; 
    std::vector<int> y ; 
    y = print_reverse(v); 
    for(auto x : y)
        std::cout << x << ", "; 
    return 0; 
}