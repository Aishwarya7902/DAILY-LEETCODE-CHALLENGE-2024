PROBLEM :https://github.com/Aishwarya7902/DAILY-LEETCODE-CHALLENGE-2024/new/main

VIDEO (MIK BHAIYA) :https://www.youtube.com/watch?v=lmLHdY7nd2M
Problem Name : Divide Array Into Arrays With Max Difference
Company Tags  : Google

/*
  TC: O(nlogn) ...since sorting
  SC: O(1) ... not taking any extra space
*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();

        vector<vector<int>>result;
        sort(begin(nums),end(nums));

        for(int i=0;i<n;i+=3){
            //checking for i,i+1,i+2
            if(nums[i+2]-nums[i]>k){ //if condition does not satisfy...just return an empty array
                return {};
            }
            // otherwise i,i+1,i+2 are valid elements
            result.push_back({nums[i],nums[i+1],nums[i+2]});


        }

     return result;
    }
};
