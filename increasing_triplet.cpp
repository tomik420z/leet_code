#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        std::vector<int> prefix_max(nums.size());
        prefix_max.back() = nums.back();
        for(int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
            prefix_max[i] = std::max(nums[i], prefix_max[i + 1]);
            
        }
        
        int N = nums.size();    
        int i = 0;
        int j = 0;
        while(j < N) {

            while(i + 1 < N && nums[i] >= nums[i + 1]) {
                ++i;
            }

            j = i + 1;

            while(j < N && nums[i] < nums[j]) {
                if (j + 1 < N && nums[j] < prefix_max[j + 1]) {
                    return true;
                }
                ++j;
            }

            i = j;
        }


        return false;
    }
};

int main() {



    return 0;
}