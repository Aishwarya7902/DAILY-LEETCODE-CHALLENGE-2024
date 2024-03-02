PROBLEM :https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

VIDEO:

/*
  BRUTE FORCE
  */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>result;
        for(int i=0;i<nums.size();i++){//TC:o(n)
            result.push_back(nums[i]*nums[i]);
        }
        sort(begin(result),end(result));//TC:o(nlogn)
        return result;
    }
};
