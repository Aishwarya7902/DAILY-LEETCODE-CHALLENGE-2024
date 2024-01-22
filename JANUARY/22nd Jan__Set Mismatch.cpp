PROBLEM :https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
VIDEO (MIK BHAIYA) :

/*
  BRUTE FORCE:
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
