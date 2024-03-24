PROBLEM :https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24

VIDEO :


/*
  APPROACH 1
  BRUTE FORCE (OWN)
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*
        story
        ->put in set
        ->if a no is already present , it means it was repeated
        */

        unordered_set<int>st;
        for(auto &num:nums){
            if(st.find(num)!=st.end())return num;
            st.insert(num);
        }
        return -1;
    }
};

/*

APPROACH 2
  SORTING
  TC:O(nlogn)
  SC:O(1)
  */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(begin(nums),end(nums)); //nlogn
        for(int i=1;i<nums.size();i++){//o(n)
            if(nums[i]==nums[i-1])return nums[i];
        }
        return -1;
    }
};


**************************************************************** UPSOLVE ************************************************************************
