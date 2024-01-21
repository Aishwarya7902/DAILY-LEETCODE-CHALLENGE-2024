PROBLEM :https://leetcode.com/problems/house-robber/?envType=daily-question&envId=2024-01-21
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=SI6Pm8AKqnQ
Problem Name : House Robber
Company Tags  : Amazon, OYO Rooms, Paytm, Walmart, Google, Flipkart, LinkedIn, Airbnb

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

/*

  BOTTOM UP
  TC: o(n)
  SC: o(n)
  */

class Solution {
public:
    int rob(vector<int>& nums) {
        int  n=nums.size();
        if(n==1)return nums[0];

        vector<int>dp(n+1,0);

        //defining a state...dp[i] =max stolen money till ith house

        //dp[0] ...zero house
        dp[0]=0;

        // dp[1]...one house

        dp[1]=nums[0];

        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+dp[i-2];
            int skip= dp[i-1];

            dp[i]=max(steal,skip);
        }

        return dp[n];
    }
};

