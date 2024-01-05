PROBLEM :https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=daily-question&envId=2024-01-05
VIDEO(MIK BHAIYA):


/*
  RECURSION :GIVES TLE
  TC:2^n
  SC:
*/

class Solution {
public:
    int n;
    int solve(int i,int prev,vector<int>& nums){
        if(i>=n)return 0;
        //take if valid condition
        int take=0,skip=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solve(i+1,i,nums);
        }
        skip=solve(i+1,prev,nums);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        return solve(0,-1,nums);
    }
};
