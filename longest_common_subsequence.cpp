#include <vector>
#include <string>
using namespace std;

// условие задачи https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> d(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for(int i = 1; i < d.size(); ++i) {
            for(int j = 1; j < d[0].size(); ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    d[i][j] = d[i - 1][j - 1] + 1;
                } else {
                    d[i][j] = std::max(d[i - 1][j], d[i][j - 1]); 
                }
            }
        }

        return d.back().back();
    }
};

int main() {


    return 0;
}