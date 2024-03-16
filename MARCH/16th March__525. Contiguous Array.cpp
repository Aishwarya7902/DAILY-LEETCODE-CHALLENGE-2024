PROBLEM :https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14

VIDEO : https://www.youtube.com/watch?v=AcSWGXBu-Xo

Company Tags  : Meta, Google


/*
  BRUTE FORCE
  generate all subarrays , if countZero==countOne , update result
 TC:O(n^2)
 SC:O(1)
  */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            int count_zero=0;
            int count_one=0;
            for(int j=i;j<n;j++){
                if(nums[j]==0)count_zero++;
                if(nums[j]==1)count_one++;
                if(count_one==count_zero){
                    result=max(result,j-i+1);
                }
            }
        }

        return result;
    }
};

/*

OPTIMISATION
replace all 0 with -1 
if a subarray has equal no of (0) -1 and 1 then its sum will be zero
hence question boils down to
finding find largest subarray with sum zero
TC:  O(n)
SC: O(1)
  */

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int result=0;
        unordered_map<int,int>mp;
        int currSum=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            currSum+=nums[i];
            int remainingSum=currSum-goal;

            if(mp.find(remainingSum)!=mp.end()){
                int j=mp[remainingSum];
                result=max(result,i-j);
            }
            mp[currSum]=i;
        }
        return result;
    }
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        unordered_map<int,int>mp;
        int currSum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            currSum+=nums[i]==1 ? 1 :-1; // replace all the zeroes with -1
            

            if(mp.find(currSum)!=mp.end()){
                
                result=max(result,i-mp[currSum]);
            }
          else  mp[currSum]=i;
        }
        return result;
      
    }
};
