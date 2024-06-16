#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//! условие задачи https://leetcode.com/problems/continuous-subarray-sum/description/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> map_rem = {{0, -1}};
        int prefix_sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            prefix_sum += nums[i];

            if (auto it = map_rem.find(prefix_sum % k); it != map_rem.end() &&
                        i - it->second >= 2) {
                return true;
            } 

            if (!map_rem.contains(prefix_sum % k)) {
                map_rem.emplace(prefix_sum % k, i);
            }
        }

        return false;
    }
};

int main() {



    return 0;
}