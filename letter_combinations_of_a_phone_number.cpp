#include <vector>
#include <string> 

using namespace std;

// условие задачи https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    std::vector<std::string> keyboard = {
        "", // 0 
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };

    vector<string> combinations; 

    void procedure(const string& digits, string prefix, int pos) {
        
        if (pos == digits.size()) {
            combinations.push_back(std::move(prefix));
        } else {
            const std::string& chars = keyboard[digits[pos] - '0'];
        
            for(char ch : chars) {        
                procedure(digits, prefix + ch, pos + 1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>{}; 
        }
        
        procedure(digits, "", 0);
        
        return combinations;
    }
};

int main() {



    return 0;
}
