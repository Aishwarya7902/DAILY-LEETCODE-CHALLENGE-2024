PROBLEM :https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

VIDEO :

/*
  BRUTE FORCE (tle)
  TC :O(N^2)
  SC:O(1)
  */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
       int n=nums.size();
       vector<int>answer(n);
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(nums[j]>nums[i])
               {
                    answer[i]=j-i;
                    break;
               }

           }
       }
       return answer; 
    }
};

