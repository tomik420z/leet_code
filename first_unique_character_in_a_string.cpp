#include <unordered_map>
#include <string>
using namespace std;

//! условие задачи 387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        std::unordered_map<char, int> m_count;

        for(int i = 0; i < s.size(); ++i) {
            ++m_count[s[i]];
        } 

        for(int i = 0; i < s.size(); ++i) {
            if (m_count[s[i]] == 1) {
                return i;
            }
        }

        return -1;

        
    }
};

int main() {



    return 0;
}