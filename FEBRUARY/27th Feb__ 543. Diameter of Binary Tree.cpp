PROBLEM :https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27

VIDEO: https://www.youtube.com/watch?v=15KwRECEXLU

Problem Name : Diameter of Binary Tree
Company Tags  : Amazon, Cadence India, Directi, MakeMyTrip, Microsoft, Oracle, OYO Rooms, Philips, Salesforce, Snapdeal, VMWare

  /*
  Companies
0 - 6 months
Facebook
55
Amazon
6
Google
3
Bloomberg
2
Apple
2
6 months - 1 year
Adobe
2
1 year - 2 years
Uber
3
Microsoft
2
Oracle
2
Wix
*/

/*
  TC:O(N)
  SC:O(1)// Auxiliary space
     O(max_depth) // Recursive stack space
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
    int result;

    int solve(TreeNode* root){
        if(!root)return 0;
        int left=solve(root->left);
        int right=solve(root->right);

        result=max(result,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        result=INT_MIN;
        solve(root);
        return result;
    }
};
