/* Write a method to replace all spaces in a string with '%20'.
 * You may assume that the string has sufficient space at the end to hold the additional characters,
 *  and that you are given the "true" length of the string.
 */

#include <iostream>
#include <string>

void bubbleUp(std::string &s, int &len, int start) {
    for (int i = len - 1; i >= start; i--) {
        s[i+1] = s[i];
    }
}

void bubbleMultiUp(std::string &s, int &len, int start, int reps) {
    for (int i = 0; i < reps; i++) {
        bubbleUp(s, len, start++);
        len++;
    }
}

void URLify(std::string &s, int len) {
    for (unsigned int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            bubbleMultiUp(s, len, i+1, 2);
            s[i] = '%';
            s[i+1] = '2';
            s[i+2] = '0';
        }
    }
}

int main() {
    std::string a("Mr John Smith    ");
    int len_a = a.length();

    std::cout << a << '|' << std::endl;
    URLify(a, len_a);
    std::cout << a << '|' << std::endl;

}
