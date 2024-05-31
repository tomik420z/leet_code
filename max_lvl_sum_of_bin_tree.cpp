#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

// условие задачи  https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/?envType=study-plan-v2&envId=leetcode-75

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    std::unordered_map<int, int> sum_levels;
    
    void procedure(TreeNode* node, int lvl) {

        sum_levels[lvl] += node->val;
        
        if (node->left != nullptr) {
            procedure(node->left, lvl + 1);
        }

        if (node->right != nullptr) {
            procedure(node->right, lvl + 1);
        }
    }

    int maxLevelSum(TreeNode* root) {
        procedure(root, 1);
        int max_lvl = 0;
        int max_sum = std::numeric_limits<int>::min();

        for(auto&&[lvl, sum] : sum_levels) {
            if (sum == max_sum && lvl < max_lvl) {
                max_sum = sum;
                max_lvl = lvl;
            }
            else if (sum > max_sum) {
                max_sum = sum;
                max_lvl = lvl;
            } 
        }

        return max_lvl;
    }
};

int main() {


    return 0;
}