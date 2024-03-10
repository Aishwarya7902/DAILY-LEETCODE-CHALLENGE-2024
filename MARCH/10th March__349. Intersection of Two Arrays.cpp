problem :https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

video :https://www.youtube.com/watch?v=rqPu9ZvLdi0

/*
Companies
0 - 6 months
Amazon
5
Apple
5
Microsoft
4
LinkedIn
4
JPMorgan
2
Yandex
2
Criteo
2
6 months - 1 year
Adobe
4
Google
2
Facebook
2
1 year - 2 years
Bloomberg
4
Two Sigma
Wix
*/

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


/*
APROACH 3:
  TC:O(M+N)
  SC:O(M)
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
         
       
        vector<int>result;
        for(auto it:nums1){
            st.insert(it);
        }
        for(int i=0;i<nums2.size();i++){
            if(st.find(nums2[i])!=st.end()){
                result.push_back(nums2[i]);
                st.erase(st.find(nums2[i]));
            }
        }

        

       

        return result;
    }
};

/*
APPROACH 4
  BINARY SEARCH
  TC:O(mlogm) + o(n*logm)
  SC:o(n)
*/

class Solution {
public:
    bool binarySearch(int target,vector<int>& nums){
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)return true;
            else if(nums[mid]<target)l=mid+1;
            else r=mid-1;
        }
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1)); //mlogm
        vector<int> result;
        unordered_set<int>st;
        for(auto num:nums2){
            if(binarySearch(num,nums1))
             st.insert(num);
        }
         for(auto it:st)
          result.push_back(it);
        
    return result;

    }
};
