#include <iostream>
#include <string.h>
#include <chrono>
#include <cmath>
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
    std::cout << "The brute force w/ backup searching algorithm took " << diff.count() << '\n'; 
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

/*
* Comparing hash values to check if the pattern is within the text. Essentially, we have a window 
* of pattern.length which checks if the hash value of the window is of the same of the pattern. 
* So, we are saying that if some hash(x) = y that for all x will give us some value y. Therefore, 
* if the value of the window is y, then we say that the pattern exists at the window's_0 index. 
*
* Requirement: Hash at the next shift must be efficiently computable at O(1) from the current hash 
* value and the next character in the text. Consider the following:
*
* Let d be the number of characters for some alphabet sigma. Let q be some prime number. Let s denote some shift. 
* Let n be the length of the txt, and m the length of the pattern. Let hash(txt[s..s+m-1]) denote the hash value at shift s. 
* Let hash(txt[s+1..s+m]) denote the hash value at next shift, s + 1.  Let h be defined as d^(m-1)
* 
* So, our rehashing function is:
* hash(txt[s+1..s+m]) = d(hash(txt[s..s+m-1]) - txt[s]*h) + txt[s+m]) mod q 
*
* Best Case: O(N+M) Worst Case: O(NM) 
*/
void rabin_karp_algorith(const char text[], const char pattern[], int num_alphabet,int prime )
{
    int text_length = strlen(text); 
    int pattern_length = strlen(pattern); 
    int pattern_hash = 0, text_hash = 0; 
    int h = pow(num_alphabet, pattern_length) -1 % prime; 
    //Calculate the hash value of pattern and first window of text 
    for(int i = 0; i < pattern_length; i++){
        pattern_hash = (num_alphabet * pattern_hash + pattern[i]) % prime; 
        text_hash = (num_alphabet *  text_hash + text[i]) % prime; 
    }
    //Slide the pattern over text one by one 
    for(int s = 0; s <= text_length - pattern_length; s++){
        //Check the hash values of current window of text and pattern. If the hash value match then 
        //only check for characters one by one. 
        if(pattern_hash == text_hash){
            //Check for characters one by one 
            int j = 0; 
            for(j = 0; j < pattern_length; j++){
                if(text[s+j] != pattern[j]) break; 
            }
            //if pattern_hash == text_hash and pattern[0..M-1] = text[i,i+1,...,i+M-1]
            if(j == pattern_length) std::cout << "Pattern found at index " << s << '\n'; 
        }

        //Calculate hash value for next window of text: remove leading digit, and trailing digit 
        if(s < text_length - pattern_length){
            //hash the next window for the text. 
            text_hash = (num_alphabet * (text_hash - text[s+1]*h) + text[s+pattern_length+1])%prime; 

        }
    }
   
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
    //Here, we are using 256 for one byte character set contains 256 characters. we use 101 since it is a prime number. 
    rabin_karp_algorith("aaaaBBBBaaaBBBBaB\0","aBBBB\0" ,2,3); 
    std::cout << '\n'; 
    return 0;
}