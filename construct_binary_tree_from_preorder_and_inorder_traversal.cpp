#include <vector>
#include <unordered_map>

using namespace std;

//! условие задачи https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

//  * Definition for a binary tree node.
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
    
    TreeNode* root;

    int get_index(const std::unordered_map<int, int>& inorder_items, int val) {
        return inorder_items.find(val)->second;
    }

    template<bool _IsLeft>
    void build_tree_impl(TreeNode* parent, //! родительский узел  
                         vector<int> preorder, //! массив вершин префиксного обхода 
                         const std::unordered_map<int, int>& inorder_items ) { //! множество индексов инфиксного обхода

        auto node = new TreeNode(preorder.front());

        if (parent == nullptr) {
            root = node;
        } else {

            if constexpr (_IsLeft) {
                parent->left = node;
            } else {
                parent->right = node;
            }

        }
         
        vector<int> left_subtree;
        vector<int> right_subtree;
        int index_item = get_index(inorder_items, preorder.front());
        
        for(auto it = ++preorder.begin(); it != preorder.end(); ++it) {
            if (index_item < get_index(inorder_items, *it)) {
                right_subtree.push_back(*it);
            } else {
                left_subtree.push_back(*it);
            }
        }

        if (!left_subtree.empty()) {
            build_tree_impl<true>(node, std::move(left_subtree), inorder_items);
        } 

        if(!right_subtree.empty()) {
            return build_tree_impl<false>(node, std::move(right_subtree), inorder_items);
        }

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        std::unordered_map<int, int> inorder_items;
        
        for(int i = 0; i < inorder.size(); ++i) {
            inorder_items[inorder[i]] = i;
        }
        build_tree_impl<false>(nullptr, preorder, inorder_items);
        return root;
        
    }
};

int main() {



    return 0;
}