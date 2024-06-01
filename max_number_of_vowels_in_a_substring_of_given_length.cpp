
#include <string>

using namespace std;

// условие задачи https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    bool is_volwes(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        // проход окном длины k по слову s
        int left = 0; 
        int right = 0;
        // кол-во гласных в текущей рассматриваемой подстроке 
        int count_volwes = 0;
        for(; right < k; ++right) {
            if (is_volwes(s[right])) {
                ++count_volwes;
            }
        }

        int max_volwes = count_volwes;    

        for(; right < s.size(); ++right, ++left) {
            
            if (is_volwes(s[right])) {
                ++count_volwes;
            }

            if (is_volwes(s[left])) {
                --count_volwes;
            }

            max_volwes = std::max(count_volwes, max_volwes);
        }

        return max_volwes;
    }
};

int main() {

    return 0;
}