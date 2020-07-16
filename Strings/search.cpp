#include <iostream>
#include <chrono>
#include <fstream>

/*
 * Essentially, this algorithm grabs some ith position, and then checks contigiously
 * on the i+j position to see if the pattern is found. We will have a time complexity 
 * of O(NM) and a space complexity of O(1); 
 * 
 * Brute force algorithms can be slow if text and pattern are repetitive. Additionally,
 * a brute force algorithm requires a backup for every mismatch. 
 */
int brute_force_search(const std::string &text,const std::string &pattern){
    for(int i = 0; i <= text.length() - pattern.length(); i++){
        int j =0; 
        for(j = 0; j < pattern.length(); j++){
            if(text[i+j]!=pattern[j]) break;
        }
        if(j == pattern.length()) return i; //the index where the pattern begins
    }
    return -1; 
}

void check_brute_force_algorith(const std::string &text, const std::string &pattern){
    auto start = std::chrono::steady_clock::now(); 
    int value =0; 
    value = brute_force_search(text, pattern); 
    if(value == -1){
        std::cout << "The pattern is not shown within the text" << '\n'; 
    }
    else std::cout << "Pattern found on position " << value << '\n'; 
    auto end = std::chrono::steady_clock::now(); 
    std::chrono::duration<double> diff = end - start; 
    std::cout << "The brute force searching algorithm took " << diff.count() << '\n'; 
}

int main(int argc, char** argv){
    //Initializing the haystack
    std::ifstream ifstream("haystack.txt"); 
    std::string haystack; 
    haystack.assign((std::istreambuf_iterator<char>(ifstream)), 
                    (std::istreambuf_iterator<char>())); 
    
    //checking execution time for brute force algorithm
    check_brute_force_algorith(haystack, "attack at dawn"); 
    
    return 0;
}