PROBLEM:https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09
VIDEO : https://www.youtube.com/watch?v=T-Fk9185a68

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
