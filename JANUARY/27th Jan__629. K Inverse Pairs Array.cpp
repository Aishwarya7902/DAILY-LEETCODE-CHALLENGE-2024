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
