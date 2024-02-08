PROBLEM :https://leetcode.com/problems/perfect-squares/?envType=daily-question&envId=2024-02-08
Problem Name : Perfect Squares 
Company Tags  : Google, Salesforce, Microsoft, Meta, Amazon
  
VIDEO :
1.RECURSION + MEMO
https://www.youtube.com/watch?v=Zbn8in7hpXY

2.BOTTOM UP
  

/*
  Recursion__ Gives TLE
  TC:
  SC:

  */
class Solution {
public:
    int solve(int n){
      if(n==0)return 0;

      int minCount=INT_MAX;
      for(int i=1;i*i<=n;i++){
          int result=1+solve(n-i*i);
          minCount=min(minCount,result);
      } 
      return minCount; 
    }

    int numSquares(int n) {
        return solve(n);

    }
};


/*
MEMOIZATION

TC:
SC:
*/

class Solution {
public:
    int dp[10001];
    int solve(int n){
      if(n==0)return 0;
      if(dp[n]!=-1)return dp[n];
      int minCount=INT_MAX;
      for(int i=1;i*i<=n;i++){
          int result=1+solve(n-i*i);
          minCount=min(minCount,result);
      } 
      return dp[n]=minCount; 
    }

    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);

    }
};
