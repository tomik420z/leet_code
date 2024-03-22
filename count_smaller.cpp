#include <iostream>
#include <vector>
using namespace std;


/*!
    @ref https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
    Учитывая целочисленный массив nums, верните целочисленный массив counts, 
    где counts[i]— количество меньших элементов справа от nums[i]. !*/

class Solution {
public:
    struct item_t {
        int value;
        int index;
    };

    void recursive_merge(vector<item_t>& nums, vector<item_t>& buffer, int left, int right, vector<int>& counters) {
        int mid = (left + right) / 2;
        if (right - left > 0) {
            recursive_merge(nums, buffer, left, mid, counters);
            recursive_merge(nums, buffer, mid + 1, right, counters);
        }

        int iv1 = left;
        int iv2 = mid + 1;
        int i = left;
        while(iv1 <= mid && iv2 <= right) {
            if (nums[iv1].value > nums[iv2].value) {
                counters[nums[iv1].index] += right - iv2 + 1;
                buffer[i++] = nums[iv1++];
            } else {
                buffer[i++] = nums[iv2++];
            }
        }

        while(iv1 <= mid) {
            buffer[i++] = nums[iv1++];
        }

        while(iv2 <= right) {
            buffer[i++] = nums[iv2++];
        }

        std::copy(buffer.begin() + left, buffer.begin() + right + 1, nums.begin() + left);
    } 

    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }

        std::vector<item_t> items;
        items.reserve(nums.size());
        for(int i = 0; i < nums.size(); ++i) {
            items.emplace_back(nums[i], i);
        }
        std::vector<item_t> buffer(nums.size());
        std::vector<int> ans(nums.size());
        recursive_merge(items, buffer, 0, items.size() - 1, ans);
        return ans;
    }
};

int main() {
    std::vector<int> v = {5, 3, 1, 5 };

    Solution sol;
    sol.countSmaller(v);

    return 0;
}
