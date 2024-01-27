PROBLEM :https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27
VIDEO (MIK BHAIYA):   (BEST EXPLANATION ON WHOLE YOUTUBE)


  /*
  RECURSION...GIVES TLE
  TC: since for every n we can try  k inversions...
   k*k*k....(n times)
   =O(k^n)
  SC: only stack space ...which equals to depth of tree

*/

  class Solution {
public:
    int MOD=1e9+7;
    int solve(int n,int k){
        if(n==0)return 0;
        if(k==0){//it means no inversion is required
            return 1;
        }

        int result=0;
        //for an array of length n ...u can have at max (n-1) inversion
        for(int inv=0;inv<=min(k,n-1);inv++){
            result = (result%MOD+solve(n-1,k-inv)%MOD)%MOD;//I already have inv inversions...now I need (k-inv) inversions
        }
        return result;
    }
    int kInversePairs(int n, int k) {
        return solve(n,k);
    }
};



/*

MEMOIZATION
SC:O(n*k)
TC: at max we are visiting (n*k) states....and for every state we have at max (n-1) inversions possible 
    O(n*k*(n-1))
*/

class Solution {
public:
    int MOD=1e9+7;
    int dp[1001][1001];
    int solve(int n,int k){
        if(n==0)return 0;
        if(k==0){//it means no inversion is required
            return 1;
        }
        if(dp[n][k]!=-1)return dp[n][k];

        int result=0;
        //for an array of length n ...u can have at max (n-1) inversion
        for(int inv=0;inv<=min(k,n-1);inv++){
            result = (result%MOD+solve(n-1,k-inv)%MOD)%MOD;//I already have inv inversions...now I need (k-inv) inversions
        }
        return dp[n][k]=result;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k);
    }
};


/*
BOTTOM UP
SC:O(n*k)
TC: at max we are visiting (n*k) states....and for every state we have at max (n-1) inversions possible 
    O(n*k*(n-1))
*/

class Solution {
public:
    int MOD=1e9+7;
    int kInversePairs(int n, int k) {
      vector<vector<int>>t(n+1,vector<int>(k+1));

      /*
      defining a state
      t[i][j]= total no. of arrays of size i with exactly j inversions

      */

      //if inversion=0 it means we have one possible way

      for(int i=0;i<=n;i++){
          t[i][0]=1;
      }

      for(int i=1;i<=n;i++){
          for(int j=1;j<=k;j++){
              int result=0;
              for(int inv=0;inv<=min(j,i-1);inv++){
                  result=(result%MOD +(t[i-1][j-inv])%MOD)%MOD;
              }
            t[i][j]=result;
          }
      }
      return t[n][k];  
    }
};
