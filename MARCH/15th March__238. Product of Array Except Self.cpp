PROBLEM : https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-03-15

VIDEO :https://www.youtube.com/watch?v=ku4oITayEmk

Company Tags  : Apple, LinkedIn, Amazon, Facebook, Microsoft

/*
  (own thought process)
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
************************************************************** UPSOLVE ********************************************************************************************

/*

APPROACH 1 (TLE)
TC:O(N^2)
SC:O(1)
  */

  class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);

        for(int i=0;i<n;i++){
            int prod=1;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                prod*=nums[j];
            }
            answer[i]=prod;
        }

        return answer;
    }
};


/*
  APPROACH 2:
  ☁️There are so many of edge cases there keep in mind
  total prod=P
  -> ans[i] =P/nums[i] ...........but what if nums[i] is 0

TC :o(n)
SC :o(1)
  */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer(n);
        int prod=1;
        int prod_without_zero=1;
        int zero_count=0;
        for(int &num:nums)
         {  if(num==0)zero_count++;
            prod*=num;
            if(num!=0)prod_without_zero*=num;
         }
        for(int i=0;i<n;i++){
           if(nums[i]!=0) answer[i]=prod/nums[i];
           else if(nums[i]==0 && zero_count<=1) answer[i]=prod_without_zero;
           else{
            answer[i]=0;
           }
           
        }

        return answer;
    }
};

/*
APPROACH 3
  TC:O(n)
  SC:O(n)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n=nums.size();
         vector<int> answer(n);
          vector<int>left(n);
          vector<int> right(n);
          left[0]=1;
          right[n-1]=1;

          
          for(int i=1;i<n;i++){
            left[i]=left[i-1]*nums[i-1];
            
          }

       
          for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]*nums[i+1];
           
          }
        for(int i=0;i<n;i++){
            answer[i]=left[i]*right[i];
        }

     return answer;
    }
};

/*
APPROACH
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n=nums.size();
         vector<int> answer(n);
         int left=1;
         int right=1;
         
        answer[0]=1;
        answer[n-1]=1;
          
          for(int i=1;i<n;i++){
            answer[i]=left*nums[i-1];
            left=answer[i];
          }

       
          for(int i=n-2;i>=0;i--){
             answer[i]*=right*nums[i+1];
             right=right*nums[i+1];
           
          }
        

     return answer;
    }
};

