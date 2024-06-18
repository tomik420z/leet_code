#include <vector>
using namespace std;

// условие задачи https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public: 
    int bin_search(int left, int right, vector<int>& nums) {

        int front = nums.front();
        int back = nums.back();

        while(left < right) {

            int mid = (left + right) / 2;

            if ((nums[mid] < front && nums[mid] < back) || (front <= nums[mid] && nums[mid] <= back)) {
                right = mid;
            } else {
                left = mid + 1;
            }

        }

        return right;
    }

    int findMin(vector<int>& nums) {
    
        int ind = bin_search(0, nums.size() - 1, nums);
        return nums[ind];
    }
};