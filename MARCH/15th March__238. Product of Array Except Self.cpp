PROBLEM : https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-03-15

VIDEO :

/*
  BRUTE FORCE
  TC:O(N^2)
  SC:O(1)
  */


class Solution {
public:
    int solvePre(vector<int>& nums,int indx){
        if (indx==0)return INT_MAX;
        int prod=1;
        for(int i=0;i<indx;i++){
            prod*=nums[i];
        }
        return prod;
    }

     int solveSuff(vector<int>& nums,int indx){
        if(indx==nums.size()-1)return INT_MAX;
        int prod=1;
        for(int i=indx+1;i<nums.size();i++){
            prod*=nums[i];
        }
        return prod;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>answer(n);
        for(int i=0;i<n;i++){
             int prefix=solvePre(nums,i);
             int suffix=solveSuff(nums,i);
             
             if(prefix==INT_MAX){
                answer[i]=suffix;
             }
             else if(suffix==INT_MAX){
                answer[i]=prefix;
             }

             else{
                answer[i]=prefix*suffix;
             }
        }

        return answer;
    }
};
