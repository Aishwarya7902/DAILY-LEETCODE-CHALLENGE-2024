 PROBLEM :https://leetcode.com/problems/range-sum-of-bst/description/?envType=daily-question&envId=2024-01-08
 VIDEO (MIK BHAIYA):

/*
  BRUTE FORCE:
  TC:
  SC:
*/

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
    int sum;
    void solve(TreeNode* root, int low, int high){
        if(!root)
          return;
        if(root->val>=low && root->val<=high){
            sum+=root->val;
        }
     solve(root->left,low,high);
     solve(root->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum=0;
        solve(root,low,high);
        return sum;
    }
};
