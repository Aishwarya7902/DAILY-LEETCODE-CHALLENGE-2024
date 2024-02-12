PROBLEM :https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12
VIDEO:https://www.youtube.com/watch?v=Q6L5SoS-fTo

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

/*

OPTIMISATION
TC: O(N)
SC: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int maj=NULL;
        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                maj=nums[i];
            }
            else if(nums[i]==maj)count++;
            else 
             count--;
        }

        return maj;
    }
};
