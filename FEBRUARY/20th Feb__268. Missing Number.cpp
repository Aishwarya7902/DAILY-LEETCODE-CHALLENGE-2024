PROBLEM :https://leetcode.com/problems/missing-number/description/?envType=daily-question&envId=2024-02-20

VIDEO : 
/*
Companies
0 - 6 months
Amazon
4
Adobe
4
Microsoft
2
Google
2
Apple
2
Nvidia
2
warnermedia
2
6 months - 1 year
Bloomberg
2
Uber
2
1 year - 2 years
Facebook
5
Yahoo
2
Oracle
2
VMware
2
Snapchat
2
*/


/*
  BRUTE FORCE 
  USING SORTING
  */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums)); //TC: O(nlogn)

        for(int i=0;i<n;i++){ // TC:O(n)
            if(i!=nums[i])return i;
        }

        return n;
    }
};


/*

METHOD 2
USING SET
TC: O(N)
SC: O(N)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(auto it:nums)
        {
          s.insert(it);
        }
         

        for(int i=0;i<=n;i++){ // TC:O(n)
            if(s.find(i)==s.end())return i;
        }

        return -1;
    }
};
