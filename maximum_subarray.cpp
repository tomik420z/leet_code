#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(int left, int right, vector<int>& nums, int& ans) {
        int mid = (left + right) / 2;
        if (left < right) {
            merge(left, mid, nums, ans);
            merge(mid + 1, right, nums, ans);
        }

        int max_left = 0;
        int curr_sum = 0;
        for(int iv1 = mid; iv1 >= left; --iv1) {
            curr_sum += nums[iv1];
            max_left = std::max(max_left, curr_sum);
        }
        
        int max_right = 0;
        curr_sum = 0;
        for(int iv2 = mid + 1; iv2 <= right; ++iv2) {
            curr_sum += nums[iv2];
            max_right = std::max(max_right, curr_sum);
        }

        ans = std::max(ans, std::max(0, max_right) + std::max(0, max_left));
    }

    int maxSubArray(vector<int>& nums) {
        
        int val = *std::max_element(nums.begin(), nums.end());
        if (val < 0) {
            return val;
        }   

        int result = 0;
        merge(0, nums.size() - 1, nums, result);

        return result;

    }
};

int main() {



    return 0;
}