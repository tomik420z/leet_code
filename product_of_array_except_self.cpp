#include <vector>

using namespace std;

//! условие задачи https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        vector<int> ans(nums.size(), 0);

        int prefix_mult = 1;
        for(int i = 0; i < nums.size(); ++i) {
            ans[i] = prefix_mult;
            prefix_mult *= nums[i];
        }

        prefix_mult = 1;
        for(int i = nums.size() - 1; i >= 0; --i) {
            ans[i] *= prefix_mult;
            prefix_mult *= nums[i];
        }
        

        return ans;


    }
};

int main() {



    return 0;
}