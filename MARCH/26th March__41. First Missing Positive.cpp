PROBLEM :https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26
video : https://www.youtube.com/watch?v=lyjOwaUEWWQ
Problem Name : First Missing Positive [HARD]

Company Tags  : META

/*

BRUTE FORCE :
TC:O(N)
SC:O(1)
  */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        int maxi=INT_MIN;
        for(auto &num:nums)
         {
            st.insert(num);
            maxi=max(maxi,num);

         }

         for(int i=1;i<maxi;i++){
            if(st.find(i)==st.end())return i;
         }
         return maxi<0 ? 1 : maxi+1;
    }
};

/*
OPTIMISATION
TC:O(N)
SC:O(1)
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();

       bool contains1=false;

       //if 1 is not present ...return 1

       // make all numbers <=0 and >n as 1..coz we dont need them

       for(int i=0;i<n;i++){
        if(nums[i]==1){
            contains1=true;
        }
        if(nums[i]<=0 || nums[i]>n)
         nums[i]=1;
       } 

       if(!contains1)return 1;

       for(int i=0;i<n;i++){
        int num=abs(nums[i]);
        int indx=num-1;

        if(nums[indx]<0)continue;
        else nums[indx]*=-1;
       }
    // if at any index , it is not neg then it was not visited
       for(int i=0;i<n;i++){
        if(nums[i]>0)return i+1;
       }

       // if all no were 1 to n ...return n+1 th no.

       return n+1;
    }
};
