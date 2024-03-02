PROBLEM :https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

VIDEO:
/*
Companies
0 - 6 months
Facebook
10
Yandex
3
Google
2
Amazon
2
Bloomberg
2
Tinkoff
2
6 months - 1 year
Yahoo
2
1 year - 2 years
Microsoft
5
Apple
4
Uber
3
PayPal
2
Walmart Labs
2
*/

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


/*
IMPROVED SOLUTION (TWO POINTER APPROACH)
TC:O(N)
SC:O(N) if you take output into account and O(1) otherwise.
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        int left=0,right=n-1;
        int j=n-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                result[j]=nums[left]*nums[left];
                left++;
            }

            else{
                result[j]=nums[right]*nums[right];
                right--;
            }
            j--;
        }

        return result;
    }
};
