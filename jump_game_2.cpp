#include <iostream>
#include <vector>
// условие задачи https://leetcode.com/problems/jump-game-ii/description/

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        
        // массив прыжков, где 
        // jumps[i] = v_i, если до i-ой ячейки возможно допрыгать 
        // v_i шагов, где v_i - минимальная дистаниция 
        vector<int> jumps(nums.size());

        int index_nums = 0;
        int index_jumps = 0;
        
        jumps[index_jumps] = 0; 
        ++index_jumps;
        for(; index_nums < nums.size(); ++index_nums) {
            
            int curr_val = nums[index_nums];
            
            int jmp = jumps[index_nums];

            while(index_jumps < jumps.size() && index_jumps <= curr_val + index_nums) {
                jumps[index_jumps] = jmp + 1;
                ++index_jumps; 
            }
        }

        return jumps.back();
    }
};

int main() {



    return 0;
}