problem :https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

video :

/*

  BRUTE FORCE :
  TC:O(M+N)
  SC:O(M+N)
  */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1;
         unordered_set<int>st2;
       
        vector<int>result;
        for(auto it:nums1){
            st1.insert(it);
        }
        for(auto it:nums2){
            st2.insert(it);
        }

        

        for(auto it:st1)
         if(st2.find(it)!=st2.end())result.push_back(it);

        return result;
    }
};

/*
APPROACH 2:
TC:O(M+N)
SC:O(M)

*/


