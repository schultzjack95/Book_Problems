/* Implement an algorithm to determine if a string has all unique characters.
 *     What if you cannot use additional data structures?
 */

#include <iostream>
#include <string>
#include <unordered_map>

bool isUnique(std::string &s) {
    std::unordered_map<char, bool> u;
    for (char& c : s) {
        auto search = u.find(c);
        if (search != u.end()) {
            return false;
        }
        u[c] = true;
    }
    return true;
}

bool isUniqueNoStructures(std::string &s) {
    for (auto i = s.begin(); i != s.end() - 1; i++) {
        for (auto j = i + 1; j < s.end(); j++) {
            if (*i == *j) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    
    std::string s("Hello world");
    std::string p("Helo wrd");

    std::cout << "\"Hello world\" is: " << (isUnique(s) ? " unique." : " not unique.") << std::endl;
    std::cout << "\"Helo wrd\" is: " << (isUnique(p) ? " unique." : " not unique.") << std::endl;


    std::cout << "\"Hello world\" is: " << (isUniqueNoStructures(s) ? " unique." : " not unique.") << std::endl;
    std::cout << "\"Helo wrd\" is: " << (isUniqueNoStructures(p) ? " unique." : " not unique.") << std::endl;
}
