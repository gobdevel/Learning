#ifndef __STRING_BASICS_H__
#define __STRING_BASICS_H__

#include <string>
#include <vector>

// Replace space with %20
inline void replaceSpaces(std::vector<char>& str, int strLength) {
    int i = 0, spaces = 0;

    // Count numbers of spaces
    for (; i < strLength; ++i) {
        if (str[i] == ' ') {
            spaces++;
        }
    }
    // Make extra space
    int end = ((spaces * 2) + strLength) - 1;
    --i;

    // start shifting characters to end
    while (i >= 0) {
        if (str[i] == ' ') {
            str[end--] = '0';
            str[end--] = '2';
            str[end--] = '%';
        } else {
            str[end--] = str[i];
        }
        --i;
    }
}

// s1 is subset of s2
inline bool isSubset(std::string& s1, std::string& s2) {
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            ++i;
        }
        ++j;
    }
    return (i == s1.size() && i != 0);
}
#endif
