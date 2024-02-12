PROBLEM :https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12
VIDEO:

/*
  BRUTE FORCE (DID BY MYSELF)
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>freq;
        for(auto it:nums){
            freq[it]++;
        }

        int target=floor(n/2);
        for(auto it:freq){
            if(it.second>target)return it.first;
        }
        return -1;
        
    }
};
