#include <iostream>
#include <vector>
using namespace std;

//! условие задачи https://leetcode.com/problems/special-array-ii/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        ans.reserve(queries.size());

        vector<int> prefix(nums.size());

        prefix[0] = 1;
        
        for(int i = 1; i < nums.size(); ++i) {

            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 1) ||
                (nums[i - 1] % 2 == 1 && nums[i] % 2 == 0)) {

                prefix[i] = prefix[i - 1];
            } else {
                prefix[i] = prefix[i - 1] + 1;
            }
        }

        for(const auto& query : queries) {
            ans.push_back(prefix[query[0]] == prefix[query[1]]);
        }

        return ans;
    }
};

int main() {



    return 0;
}