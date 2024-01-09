PROBLEM:https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09
VIDEO(MIK BHAIYA): https://www.youtube.com/watch?v=rlWJlXQNt0Q
Problem Name : Leaf-Similar Trees
Company Tags  : Meta, Microsoft, Twitter, Amazon, Goldman Sachs

/*
  BRUTE FORCE (solved on my own)
  algo: put all leaf nodes of tree 1 in a vector , repeat the same for tree 2 ....check if vector 1 == vector 2
  TC: O(n)
  SC: O(n)
*/

class Solution {
public:
    void findLeafNode(vector<int>&v ,TreeNode* root){
        if(root==NULL)return;
        if(!root->left && !root->right)
         v.push_back(root->val);
        findLeafNode(v,root->left);
        findLeafNode(v,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;

        findLeafNode(v1,root1);
        findLeafNode(v2,root2);
       
    return v1==v2;

    }
};

/*
  OPTIMISATION  (USING A STRING)
  //T.C : O(n)
//S.C : O(n) (string s) - I am ignoring the recursion stack space here
*/


class Solution {
public:
    void findLeafNode(string &s ,TreeNode* root){
        if(root==NULL)return;
        if(!root->left && !root->right)
         {
             s+=to_string(root->val)+"_";
         }
        findLeafNode(s,root->left);
        findLeafNode(s,root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="";
        string s2="";

        findLeafNode(s1,root1);
        findLeafNode(s2,root2);
       
    return s1==s2;

    }
};
