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
TC:o(mlogm) + o(nlogn) + o(m+n)
SC: o(1)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1)); //mlogm
        sort(begin(nums2),end(nums2)); //nlogn
        
        vector<int> result;
        int m=nums1.size();
        int n=nums2.size();

        int i=0,j=0;
        while(i<m && j<n){ //o(m+n)
            if(nums1[i]<nums2[j]){
                i++;
            }

            else if(nums1[i]>nums2[j]){
                j++;
            }

            else if(nums1[i]==nums2[j] ){
               if(result.size()==0) result.push_back(nums1[i]);
               else if(nums1[i]!=result.back()) result.push_back(nums1[i]);
                i++;
                j++;
            }
            
        }
    return result;

    }
};


