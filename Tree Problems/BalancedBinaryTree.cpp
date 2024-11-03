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
    // Helper function that returns a pair of <isBalanced, height>
    pair<bool, int> height(TreeNode* root) {
        if (root == NULL) return {true, 0};

        // Recursively get the balance and height of left and right subtrees
        pair<bool, int> left = height(root->left);
        pair<bool, int> right = height(root->right);

        // Check if the left and right subtrees are balanced
        bool isLeftBalanced = left.first;
        bool isRightBalanced = right.first;

        // Calculate the height of the current subtree
        int height = max(left.second, right.second) + 1;

        // Check if the current node is balanced
        bool isBalanced = isLeftBalanced && isRightBalanced && abs(left.second - right.second) <= 1;

        return {isBalanced, height};
    }

    bool isBalanced(TreeNode* root) {
        // Check the balance of the entire tree
        return height(root).first;
    }
};
