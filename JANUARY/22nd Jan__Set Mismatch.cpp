PROBLEM :https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
VIDEO (MIK BHAIYA) : https://www.youtube.com/watch?v=j89Yzq3IwVY
Problem Name : Set Mismatch (Leetcode 645)
Company Tags  : Amazon

/*
  BRUTE FORCE:(solved on own)
  TC: O(n)
  SC: O(n)
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n=nums.size();
      unordered_map<int,int>mp;
      for(auto it:nums){
          mp[it]++;
      }
      int notPresent;
      int repeated;
      for(int i=1;i<=n;i++){
          if(mp.find(i)==mp.end()){
              notPresent=i;
          }
          else if(mp[i]==2){
              repeated=i;
          }
      }
      return {repeated,notPresent};
    }
};

/*
  OPTIMISATION...watch the video...u will understand better
  TC:O(N)
  SC:O(1)
  */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int duplicate=-1;
        int missing=-1;

        for(int i=0;i<n;i++){
            if(nums[abs(nums[i])-1]<0)
             duplicate= abs(nums[i]);
            else
             nums[abs(nums[i])-1]*=(-1);
        }

        for(int i=0;i<n;i++){
            if(nums[i]>0)
             missing=(i+1);
        }
        return {duplicate,missing};
    }
};
