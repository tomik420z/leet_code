#include <vector>

using namespace std;
// условие https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_length = nums.size() + 1;

        int left = 0;
        int right = 0;
        int curr_sum = 0;
        while(left < nums.size()) {
            while(right < nums.size() && curr_sum < target) {
                curr_sum += nums[right];
                ++right;
            }

            if (curr_sum >= target) { 
                min_length = std::min(min_length, right - left);
            }

            curr_sum -= nums[left];
            ++left;
            
            if (right < nums.size() && left > right) {
                curr_sum += nums[right];
                ++right;
            }
            
        }

        if (min_length == nums.size() + 1) {
            return 0;
        } else {
            return min_length;
        }
    }
};

int main() {


    return 0;
}