PROBLEM:https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09
VIDEO : https://www.youtube.com/watch?v=T-Fk9185a68
Problem Name : Largest Divisible Subset
Company Tags  : Google
/*
  BRUTE FORCE (recursion)
  TC:O(2^n)
  SC:

*/

class Solution {
public:

    void solve(int indx,vector<int>& nums,vector<int>& result,vector<int>& temp,int prev){
        if(indx>=nums.size()){
            if(temp.size()>result.size()){
                result=temp;
            }
            return;
        }

        //taken 
        if(prev==-1 || nums[indx]%prev==0){
            temp.push_back(nums[indx]);
            solve(indx+1,nums,result,temp,nums[indx]);
            temp.pop_back();//not taken
        }
        //not taken
       solve(indx+1,nums,result,temp,prev); 
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));//most crucial step

        vector<int>result;
        vector<int>temp;
        int prev=-1;
        solve(0,nums,result,temp,prev);

        return result;

    }
};


/*
BOTTOM UP
TC:O(N^2)
SC:
*/


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));//most crucial step
        vector<int> dp(n,1);
        vector<int> prev_indx(n,-1);

        int last_chosen_indx=0;
        int maxL=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        prev_indx[i]=j;
                    }

                    if(dp[i]>maxL){
                        maxL=dp[i];
                        last_chosen_indx=i;
                    }
                }
            }
        }

        vector<int>result;
        while(last_chosen_indx!=-1){
            result.push_back(nums[last_chosen_indx]);
            last_chosen_indx=prev_indx[last_chosen_indx];
        }

        return result;

    }
};
