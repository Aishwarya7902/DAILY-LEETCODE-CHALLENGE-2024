PROBLEM :https://leetcode.com/problems/subarrays-with-k-different-integers/description/?envType=daily-question&envId=2024-03-30

VIDEO :

/*
  BRUTE FORCE (DOUBLE FOR LOOP)
  TC:O(N^2)
  SC:O(1)
  */

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int result=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                if(st.size()==k){
                    result++;
                }
            }
        }
        return result;
    }
};
