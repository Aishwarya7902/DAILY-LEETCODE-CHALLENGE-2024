PROBLEM :
VIDEO (MIK BHAIYA):

/*
  BRUTE FORCE
  RECURSION (gives tle)
  TC: O(2^n) // at every index we have two choice...take or not take
  SC: O(1) // we are not taking any extra space ...except..auxiliary stack for recursion

  */

class Solution {
public:
    int n;
    int solve(int indx,vector<int>& nums){
       if(indx>=n)return 0;

       int take= nums[indx]+solve(indx+2,nums);
       int not_take= solve(indx+1,nums);
       return max(take,not_take);
    }
    int rob(vector<int>& nums) {
        n=nums.size();

        return solve(0,nums);
    }
};


/*
  MEMOIZATION 
  TC: O(N)
  SC: O(1) //since constraints are low
  */

class Solution {
public:
    int dp[101];
    int n;
    int solve(int indx,vector<int>& nums){
       if(indx>=n)return 0;

       if(dp[indx]!=-1)return dp[indx];

       int take= nums[indx]+solve(indx+2,nums);
       int not_take= solve(indx+1,nums);
       return dp[indx]= max(take,not_take);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};

