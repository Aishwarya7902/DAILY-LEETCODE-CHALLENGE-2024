PROBLEM :https://leetcode.com/problems/subarray-product-less-than-k/description/?envType=daily-question&envId=2024-03-27

VIDEO :https://www.youtube.com/watch?v=9fmKB1F1pEE
Problem Name : Subarray Product Less Than K
Company Tags  : Yatra

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


/*
SLIDING WINDOW APPROACH
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
     /*
      IMPORTANT CORNER CASE
      */

      if(k<=1)return 0;// since no. are always >=1 , 
      //hence it's never possible to find a subarray with prod<1
        int count=0;
        int i=0;
        int j=0;
        int prod=1;
        while(j<n){
            prod*=nums[j];
            while(prod>=k){ //untill condition violates remove ith index
             prod/=nums[i];
             i++;

            }

            // now condition is valid
            count+=j-i+1;//no. of subarrays ending at j
            j++;
        }

        return count;
    }
};
