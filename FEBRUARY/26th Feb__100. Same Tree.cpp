PROBLEM :https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26

VIDEO :

/*
Companies
0 - 6 months
Amazon
3
Google
3
LinkedIn
2
Microsoft
2
tcs
2
1 year - 2 years
Apple
7
Adobe
3
Facebook
2
Bloomberg
*/

/*

  BRUTE FORCE
  TC:O(N)
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
    //helper
    bool solve(TreeNode* p, TreeNode* q) {
        if(!p && !q)return true;
        if(!p && q!=NULL)return false;
        if(!q && p!=NULL)return false;

        if(p->val !=q->val)return false;

        if(solve(p->left,q->left)==false)return false;
        if(solve(p->right,q->right)==false)return false;

     return true;
    }
    //main
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};
