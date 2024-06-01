#include <vector>
using namespace std;

// условие задачи https://leetcode.com/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=leetcode-75

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
    void procedure(TreeNode* node, vector<int>& right_side, int lvl) {
        if (right_side.size() <= lvl) {
            right_side.push_back(node->val);
        } else {
            right_side[lvl] = node->val;
        }

        if (node->left != nullptr) {
            procedure(node->left, right_side, lvl + 1);
        } 
        
        if (node->right != nullptr) {
            procedure(node->right, right_side, lvl + 1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        procedure(root, ans, 0);
        return ans;
    }
};

int main() {



    return 0;
}