PROBLEM : https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14

VIDEO :

/*
  BRUTE FORCE (GAVE TLE)
  TC: O(N^2)
  SC: O(1)
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                if(sum==goal)count++;
                if(sum>goal)break;
            }
        }
     return count;
    }
};

/*
OPTIMISATION
USING CUMULATIVE SUM
TC:O(N)
SC:O(N)
*/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int result=0;
        unordered_map<int,int>mp;
        int currSum=0;
        mp[0]=1;
        for(int &num:nums){
            currSum+=num;
            int remainingSum=currSum-goal;

            if(mp.find(remainingSum)!=mp.end()){
                result+=mp[remainingSum];
            }
            mp[currSum]++;
        }
        return result;
    }
};
