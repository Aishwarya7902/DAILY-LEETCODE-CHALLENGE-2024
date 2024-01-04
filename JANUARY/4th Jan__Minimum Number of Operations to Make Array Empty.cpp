PROBLEM:https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/?envType=daily-question&envId=2024-01-04
VIDEO(MIK BHAIYA): https://www.youtube.com/watch?v=lkPNh2M1lUs

/*
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // take  a map to store frequency
       unordered_map<int,int>freq;
       // visit nums and store freq in map
       for(int &num: nums)
        {
            freq[num]++;
        }

        //take a result variable
        int result=0;
        // visit map and do the operations

        for(auto it:freq){
            int curr_freq=it.second;
            if(curr_freq==1)return -1;
            
            result+=ceil((double)curr_freq/3);

        }

     return result;

    }
};


