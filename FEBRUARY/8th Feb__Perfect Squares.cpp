PROBLEM :https://leetcode.com/problems/perfect-squares/?envType=daily-question&envId=2024-02-08
Problem Name : Perfect Squares 
Company Tags  : Google, Salesforce, Microsoft, Meta, Amazon
Frequency     : 74%
  
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
This question is nothing but just similar to of "Minimum Coins to get sum S (COIN CHANGE - Leetcode : 322)
TC:O(n*S) - Where n = total coins possible and S = target sum
SC:O(n*S)
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


/*

BOTTOM UP
TC:O(N*N)
SC:O(N)
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,100000);

        //defining states
        //dp[i]= minimum no. of perfect squares to get i
        // return dp[n]

       dp[0]=0;
       for(int i=1;i<=n;i++){
           for(int j=1;j*j<=i;j++){
               dp[i]=min(dp[i],1+dp[i-j*j]);
           }
       }

       return dp[n];
    }
};
