PROBLEM :https://leetcode.com/problems/perfect-squares/?envType=daily-question&envId=2024-02-08

VIDEO :
1.RECURSION + MEMO
https://www.youtube.com/watch?v=Zbn8in7hpXY

*/
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
    
