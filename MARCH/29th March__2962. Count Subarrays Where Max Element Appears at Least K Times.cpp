PROBLEM :https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

video :https://www.youtube.com/watch?v=06VaWkj8e-0

/*
  BRUTE FORCE (TLE)
  TC:O(N^2)
  SC:O(1)
  */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result=0;
        int n=nums.size();
        int hero=0;
        for(auto it:nums)hero=max(hero,it);

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==hero)cnt++;
                if(cnt>=k)result++;
            }
        }

        return result;
    }
};

/*
OPTIMIZATION
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result=0;
        int n=nums.size();
        int maxE=*max_element(begin(nums),end(nums));
        int i=0;
        int j=0;
        int countMax=0;
        while(j<n){
            if(nums[j]==maxE)countMax++;
            while(countMax>=k){
                result+=n-j;
                if(nums[i]==maxE){
                    countMax--;
                }
                i++;
            }
            j++;

        }

        return result;
    }
};
