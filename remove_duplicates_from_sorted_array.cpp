#include <vector>
using namespace std;
// условие задачи https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }

        auto out_it = nums.begin(); // итератор записи 
        auto curr_it = nums.begin(); // текущий проссматриваемый эл-т
    
        while(curr_it != nums.end()) {
            auto prev_it = curr_it;  
            ++curr_it;

            while(curr_it != nums.end() && *curr_it == *prev_it) {
                ++curr_it;
            }

            *out_it = *prev_it;
            ++out_it;
        }        

        return std::distance(nums.begin(), out_it);
    }
};

int main() {

    

    return 0;
}