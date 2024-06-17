#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//! условие задачи https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // использование префиксных сумм, хранящихся в хэш-таблице
        std::unordered_map<int, int> intervals = {{0, 1}};
        int prefix_sum = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
        
            prefix_sum += nums[i];

            if (auto it = intervals.find(prefix_sum - k); 
                                it != intervals.end()) {   
                cnt += it->second;
            }

            intervals[prefix_sum] += 1; 
        }   

        return cnt;
    }
};

int main() {
    




    return 0;
}