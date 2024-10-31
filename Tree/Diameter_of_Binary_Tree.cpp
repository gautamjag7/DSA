/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function that returns a pair of <diameter, height>
    pair<int, int> height(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        pair<int, int> left = height(root->left);
        pair<int, int> right = height(root->right);

        // Calculate the diameter through the current node
        int diameterThroughRoot = left.second + right.second;
        
        // Find the largest diameter
        int diameter = max(left.first, max(right.first, diameterThroughRoot));
        
        // Calculate the height of the current node
        int height = 1 + max(left.second, right.second);

        return {diameter, height};
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        return height(root).first;
    }
};
