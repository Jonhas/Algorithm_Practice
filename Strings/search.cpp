#include <iostream>
#include <chrono>
#include <fstream>

/*
 * Essentially, this algorithm grabs some ith position, and then checks contigiously
 * on the i+j position to see if the pattern is found. We will have a time complexity 
 * of O(NM) and a space complexity of O(1). Always shifts the "window" by exactly
 * 1 position to the right. mn expected text characters comparisons. 
 * 
 * Time complexity for preprocessing is none, it has no processing. While the time 
 * complexity for matching is Θ(NM). 
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


/*
 * An approach to avoid backup while doing the brute force algorithm is to maintain
 * a buffer of last m characters. The same sequence of char compares as previous 
 * implementations. 
 *      i points to end of sequence of already-matched chars in text
 *      j stores number of already-matched chars (end of sequence in pattern)
 */

int brute_force_no_backup(const std::string &text, const std::string &pattern){
    int i = 0, j = 0; 
    for(i = 0, j = 0; i < text.length() && j < pattern.length(); i++){
        if(text[i] == pattern[j]) j++; 
        else {i-=j;j=0;} //explicit backup
    }
    if(j == pattern.length()) return i - pattern.length();
    else return -1;  
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
    std::cout << "The brute force rm.searching algorithm took " << diff.count() << '\n'; 
}

void check_brute_force_no_backup(const std::string &text, const std::string &pattern){
    auto start = std::chrono::steady_clock::now(); 
    int value = 0; 
    value = brute_force_no_backup(text, pattern); 
    if(value == -1)
        std::cout << "The pattern is not shown within the text" << '\n'; 
    else std::cout << "Pattern found on position " << value << '\n'; 
    auto end = std::chrono::steady_clock::now(); 
    std::chrono::duration<double> diff = end - start; 
    std::cout << "The brute force  with explicit backup searching algorithm took " << diff.count() << '\n'; 
}

int main(int argc, char** argv){
    //Initializing the haystack
    std::ifstream ifstream("haystack.txt"); 
    std::string haystack; 
    haystack.assign((std::istreambuf_iterator<char>(ifstream)), 
                    (std::istreambuf_iterator<char>())); 
    
    //checking execution time for brute force algorithm
    check_brute_force_algorith(haystack, "attack at dawn"); 
    check_brute_force_no_backup(haystack, "attack at dawn"); 
    std::cout << '\n'; 
    return 0;
}