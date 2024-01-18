PROBLEM :https://leetcode.com/problems/climbing-stairs/submissions/1149770588/?envType=daily-question&envId=2024-01-18

VIDEO (MIK BHAIYA) :

/*
  RECURSION
  TC:
  SC:
  */

class Solution {
public:
    int solve(int n){
        if(n<=1)return 1;
        
        if(n==2)return 2;

        return solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
       return solve(n); 
    }
};


/*
  MEMOZATION 
  TC:
  SC:
*/

class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n<=1)return 1;
        
        if(n==2)return 2;
        if(dp[n]!=-1)return dp[n];

        return dp[n]=solve(n-1)+solve(n-2);
    }
    int climbStairs(int n) {
       memset(dp,-1,sizeof(dp));
       return solve(n); 
    }
};
