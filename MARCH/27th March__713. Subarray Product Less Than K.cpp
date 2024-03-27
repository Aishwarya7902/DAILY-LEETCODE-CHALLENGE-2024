PROBLEM :https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

VIDEO :

/*
  BRUTE FORCE
  1.find all subarrays
  2.if product of that subarray <k .......cnt++
  3.return cnt

 Tc: O(n^2)
 Sc: O(1)
  */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();

        int count=0;
        for(int i=0;i<n;i++){
            long long prod=1;
            for(int j=i;j<n;j++){
                prod*=nums[j];
                if(prod<k)count++;
                else break;
            }
        }

        return count;
    }
};
