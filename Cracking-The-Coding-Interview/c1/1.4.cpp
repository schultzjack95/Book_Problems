/* Palindrome Permutation - Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters. The palindrome does ont need to be limited to just dictionary words.
 * Spaces are to be ignored; i.e. 'taco cat' is a palindrome.
 */

#include <iostream>
#include <string>
#include <algorithm>


/* A palindrome will have an even number of each character, with at most 1 exception (the center of the palindrome). So if we sort the string so that all like characters are adjacent, then check if there is more than one character with odd count.
 */

bool is_palindrome_permutation(std::string s) {
    std::sort(s.begin(), s.end());
    
    int count = 1;
    bool hasSingle = false;
    
    for (unsigned int i = 1; i < s.length(); i++) {
        if (s[i] != s[i-1]) {
            if (count % 2 == 1) {
                if (s[i-1] == ' ') {
                    count = 1;
                    continue;
                }

                if (hasSingle) {
                    return false;
                } else {
                    hasSingle = true;
                }
            }
            count = 1;
        } else {
            count++;
        }
    }
    return true;
}

int main() {
    // Possible strings to check: "tact coa", "aaa"
    std::string a("abc");
    if (is_palindrome_permutation(a)) {
        std::cout << "String: \'" << a << "\' is a palindrome permutation." << std::endl;
    } else {
        std::cout << "String: \'" << a << "\' is not a palindrome permutation." << std::endl;
    }

    a = "tact coa";
    if (is_palindrome_permutation(a)) {
        std::cout << "String: \'" << a << "\' is a palindrome permutation." << std::endl;
    } else {
        std::cout << "String: \'" << a << "\' is not a palindrome permutation." << std::endl;
    }
}
