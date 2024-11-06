class Solution {
public:
    bool hasPathSum(TreeNode* root, int ts)
     {
        if (root == NULL) {
            return false;
        }
        
        // Subtract the current node's value from the target sum
        ts -= root->val;
        
        // Check if it's a leaf node and the sum matches the target
        if (root->left == NULL && root->right == NULL) {
            return ts == 0;
        }
        
        // Recursively check the left and right subtrees
        return hasPathSum(root->left, ts) || hasPathSum(root->right, ts);
    }
};