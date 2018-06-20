#include <iostream>
#include <string>
#include <unordered_map>

// Given two strings, decide if one is a permutation of the other.

bool isPermutation(std::string &s1, std::string &s2) {
    
    // Construct a map containing the frequecy of each character in the first string
    std::unordered_map<char, int> u;
    for (char& c : s1) {
        // if c is already in the map, increment it.
        auto search = u.find(c);
        if (u.find(c) != u.end()) {
            search->second++;
        } else { // else add it in with frequency 1
            u.insert({c, 1});
        }
    }

    // Compare the frequencies of the two strings by subtracting the second's from the first's.
    for (char& c : s2) {
        auto search = u.find(c);
        if (u.find(c) == u.end()) {
            return false;
        } else {
            if (search->second >= 1) {
                search->second--;
            } else {
                return false;
            }
        }
    }

    // Sum up the unmatched letters. If it is NOT 0, the two strings are not permutations.
    int count = 0;
    for (auto iter = u.begin(); iter != u.end(); ++iter) {
        count += iter->second;
    }
    return count == 0;
}


int main() {
    std::string s("hello world");
    std::string p("olleh drlow");
    std::string d("Hello World");

    std::cout << "Strings \"" << s << "\" and \"" << p << "\" are " << (isPermutation(s, p) ? "permutations" : "not permutations")              << " of each other." << std::endl;
    
    std::cout << "Strings \"" << s << "\" and \"" << d << "\" are " << (isPermutation(s, d) ? "permutations" : "not permutations")              << " of each other." << std::endl;

    std::cout << "Strings \"" << p << "\" and \"" << d << "\" are " << (isPermutation(p, d) ? "permutations" : "not permutations")              << " of each other." << std::endl;

}
