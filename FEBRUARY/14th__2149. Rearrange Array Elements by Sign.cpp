PROBLEM :https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14
VIDEO:
/*
Companies
0 - 6 months
Adobe
2
Apple
2
6 months - 1 year
Bloomberg
3
Amazon
2
Uber
2
*/

/*
  BRUTE FORCE (DONE BY MYSELF)
  TC: O(N)
  SC:O(N/2)+O(N/2)

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>result;
        int n=nums.size();
        vector<int>neg;
        vector<int>pos;
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num<0)neg.push_back(num);
            else
             pos.push_back(num);
        }

        int i=0,j=0;
        while(i<n/2 && j<n/2){
            result.push_back(pos[i]);
            i++;
            result.push_back(neg[j]);
            j++;
        }

        return result;
    }
};
