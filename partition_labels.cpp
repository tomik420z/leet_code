#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// условие задачи https://leetcode.com/problems/partition-labels/

class Solution {
public:

    vector<int> partitionLabels(string s) {
        std::unordered_map<char, int> right_set;
        for(int i = 0; i < s.size(); ++i) {
            right_set[s[i]] = i; 
        }
        vector<int> result;

        int i = 0;
        while(i < s.size()) {
            
            int right_border = right_set[s[i]];

            if (right_border == i) {
                result.push_back(1);
                ++i;
                continue;
            }

            int left = i; 

            while(i <= right_border) {
                right_border = std::max(right_border, right_set[s[i]]);
                ++i;
            }

            result.push_back(i - left);
        }
        return result;
    }
};

int main() {



    return 0;
}