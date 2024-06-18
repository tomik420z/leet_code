#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

// условие задачи https://leetcode.com/problems/contiguous-array/

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int, int> prefix_map = {{0, -1}};
        int prefix_sum = 0;
        int longest_subarray = 0;
        for(int i = 0; i < nums.size(); ++i) {

            prefix_sum += (nums[i] == 0) ? -1 : 1;

            if (auto it = prefix_map.find(prefix_sum); 
                      it != prefix_map.end()) {

                longest_subarray = std::max(longest_subarray, i - it->second); 
            } else {
                prefix_map.emplace(prefix_sum, i);
            }
        }

        return longest_subarray;

    }
};

int main() {



    return 0;
}