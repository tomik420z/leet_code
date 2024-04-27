#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//! условие задачи https://leetcode.com/problems/max-number-of-k-sum-pairs/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        
        int i = 0;
        int j = nums.size() - 1;
        int cnt = 0;
        while(i < j) {
            if (nums[i] + nums[j] == k) {
                ++cnt;
                ++i;
                --j;
            } else if (nums[i] + nums[j] < k) {
                ++i;
            } else {
                --j;
            }
        
        }
        return cnt;

    }

};

int main() {



    return 0;
}