#include <unordered_map>
using namespace std;

// условие задачи https://leetcode.com/problems/binary-tree-maximum-path-sum/

//! Definition for a binary tree node.
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
    std::unordered_map<TreeNode*, int> cost;
    // считаем макисмальный путь до литса для каждого узла дерева 
    void calc_path_vertex(TreeNode* curr) {
        if (curr->left != nullptr) {
            calc_path_vertex(curr->left);
        } 
        
        if (curr->right != nullptr) {
            calc_path_vertex(curr->right);
        }

        int left_max = (curr->left != nullptr) ? cost[curr->left] : 0;
        int right_max = (curr->right != nullptr) ? cost[curr->right] : 0;
        cost[curr] = std::max(0, std::max(left_max, right_max) + curr->val);
        
    }

    void calc_max_cost(TreeNode* curr, int& max_sum) {

        int path_left = (curr->left != nullptr) ? cost[curr->left] : 0;
        int path_right = (curr->right != nullptr) ? cost[curr->right] : 0;
        max_sum = std::max(max_sum, path_left + path_right + curr->val); 
        
        if (curr->left != nullptr) {
            calc_max_cost(curr->left, max_sum);
        } 
        
        if (curr->right != nullptr) {
            calc_max_cost(curr->right, max_sum);
        }
    }

    int maxPathSum(TreeNode* root) {
        calc_path_vertex(root);
        
        int max_path_sum = root->val;
        calc_max_cost(root, max_path_sum);

        return max_path_sum;
    }  
};

int main() {


    return 0;
}