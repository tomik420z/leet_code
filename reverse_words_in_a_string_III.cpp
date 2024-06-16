#include <string>

using namespace std;

//! условие задачи https://leetcode.com/problems/reverse-words-in-a-string-iii/description/

class Solution {
public:
    void reverse_word(string& s, int left, int right) {
        while(left < right) {
            std::swap(s[left], s[right]);
            ++left;
            --right;
        }
    }

    string reverseWords(string s) {
        int left = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse_word(s, left, i - 1);
                left = i + 1;
            }
        }

        reverse_word(s, left, s.size() - 1);

        return s;
    }
};

int main() {



    return 0;
}