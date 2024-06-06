#include <vector>
#include <algorithm>
using namespace std;

// условие задачи https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());
        int max_candy = *std::max_element(candies.begin(), candies.end());
        for(int i = 0; i < candies.size(); ++i) {
            if (candies[i] + extraCandies >= max_candy) {
                ans[i] = true;
            }
        }

        return ans;
    }
};

int main() {


    return 0;
}