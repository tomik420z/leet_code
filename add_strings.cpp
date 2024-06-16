#include <string>
#include <algorithm>
using namespace std;

// условие задачи https://leetcode.com/problems/add-strings/description/

class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        auto it = num1.rbegin();
        auto jt = num2.rbegin();
        bool memory = false;
        for(; it != num1.rend() && jt != num2.rend(); ++it, ++jt) {
            char num = (*it - '0') + (*jt - '0');
            num = memory ? num + 1 : num;
            memory = false;

            if (num > 9) {
                memory = true;
            }

            ans += (num % 10 + '0');
        }

        while(it != num1.rend()) {
            char num = (*it - '0');
            num = memory ? num + 1 : num;
            memory = false;

            if (num > 9) {
                memory = true;
            }

            ans += (num % 10 + '0');
            
            ++it;
        }

        while(jt != num2.rend()) {
            char num = (*jt - '0');
            num = memory ? num + 1 : num;
            memory = false;

            if (num > 9) {
                memory = true;
            }

            ans += (num % 10 + '0');
            
            ++jt;
        }

        if (memory) {
            ans += '1';
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {


    return 0;
}