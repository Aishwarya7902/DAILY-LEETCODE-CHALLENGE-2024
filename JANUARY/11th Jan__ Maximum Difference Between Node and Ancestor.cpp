PROBLEM :https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/?envType=daily-question&envId=2024-01-11

VIDEO(MIK BHAIYA):

/*
  BRUTE FORCE ( SOLVED ON MY OWN ❤️)
  ALGO:
  The key idea is:
  1.take a result=INT_MIN;
  2. take a node as parent....go to every single ancestor....update result
  3. repeat step 2 for every node as parent
  TC: o(n^2)
  SC :o(1) as we are not taking any extra space

*/

class Solution {
public:
    int result;
    void helper(TreeNode* parent,TreeNode* child){
        if(!parent || !child)return;
        int value=abs(parent->val-child->val);
        result=max(result,value);

        helper(parent,child->left);
        helper(parent,child->right);
    }
    void solve(TreeNode* root){
        if(!root)return;
        if(root->left)helper(root,root->left);
        if(root->right)helper(root,root->right);

        solve(root->left);
        solve(root->right);

    }
    int maxAncestorDiff(TreeNode* root) {
        result=INT_MIN;
        solve(root);
        return result;
    }
};
