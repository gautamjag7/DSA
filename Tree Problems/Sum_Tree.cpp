/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<bool, int> solve(Node *root)
    {
        pair<bool, int> ans;
        if(root==NULL) return {true, 0};
        if (root->left == NULL && root->right == NULL) 
            return {true, root->data};
        pair<bool, int> left=solve(root->left);
        pair<bool, int> right = solve(root->right);
        if(left.first && right.first && root->data == left.second+ right.second)
        {
            ans.first=true;
            ans.second=root->data + left.second+ right.second;
        }
        else {
            ans.first=false;
        }
        return ans;
    }
    bool isSumTree(Node* root) 
    {
        
        return solve(root).first;
    }
};