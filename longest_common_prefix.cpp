#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Условие задачи https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    bool is_contains_ch(vector<string>& strs, int index, char ch) {
        for(const auto& str : strs) {
            if (index >= str.size() || str[index] != ch) {
                return false;
            } 
        }
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }

        string prefix;
        prefix.reserve(strs[0].size());
        
        bool prefix_is_find = false;
        int j = 0;
        while(!prefix_is_find) {
            if (j >= strs[0].size()) {
                break;
            }

            char ch = strs[0][j];
            if (is_contains_ch(strs, j, ch)) {
                prefix += ch;
            } else {
                prefix_is_find = true;
            }
            ++j;
        }

        return prefix;
    }
};

int main() {



    return 0;
}