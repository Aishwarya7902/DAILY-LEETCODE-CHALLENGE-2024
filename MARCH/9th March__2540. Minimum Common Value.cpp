PROBLEM :https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09

VIDEO :

/*
Companies
0 - 6 months
Amazon
2
6 months - 1 year
Apple
2
1 year - 2 years
Microsoft

*/




/*
  BRUTE FORCE
  TC:O(M+N)
  SC:O(M)
*/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      int result=INT_MAX;
      unordered_set<int>st;
      for(auto it:nums1)
       st.insert(it);

      for(auto it:nums2){
          if(st.find(it)!=st.end()){
              result=min(result,it);
          }
      } 
      return result==INT_MAX ? -1 :result; 
    }
};
