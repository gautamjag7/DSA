class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        // Case 1: Both nodes are null, so they are the same
        if (p == nullptr && q == nullptr)
            return true;
        
        // Case 2: One of the nodes is null, but the other is not
        // This means the trees are not the same
        if (p == nullptr || q == nullptr)
            return false;
        
        // Case 3: Both nodes are not null, so we check their values
        // and recursively check their left and right subtrees
        if (p->val != q->val)
            return false;
        
        // Recursively check if both the left subtrees and the right subtrees are the same
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
