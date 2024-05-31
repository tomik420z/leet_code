#include <vector>
#include <algorithm>

using namespace std;

// условие задачи  https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        std::vector<int> d;
        d.reserve(nums.size());
        d.emplace_back(nums[0]);

        for(int num : nums) {
            if (d.back() < num) {
                d.push_back(num);
            } else {
                auto it = std::lower_bound(d.begin(), d.end(), num);
                *it = num;
            }   
        }
        
        return d.size();
    }
};

int main() {

    return 0;
}