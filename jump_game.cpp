#include <iostream>
#include <vector>

using namespace std;

/*
    условие задачи: https://leetcode.com/problems/jump-game/description/
*/

class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        if (nums.front() == 0 && nums.size() > 1) {
            return false;
        }
        // массив прыжков, где 
        // jumps[i] = true, если до i-ой ячейки возможно допрыгать 
        // jumps[i] = false, иначе
        vector<bool> jumps(nums.size());
        int index_nums = 0;
        int index_jumps = 0;
        
        jumps[index_jumps] = true; 
        for(; index_nums < nums.size(); ++index_nums) {
            
            int curr_val = nums[index_nums];
            
            if (jumps[index_nums] == false) {
                return false;
            }

            while(index_jumps < jumps.size() && index_jumps <= curr_val + index_nums) {
                jumps[index_jumps] = true;
                ++index_jumps; 
            }
 
        }

        return jumps.back();
    }
};

int main() {



    return 0;
}