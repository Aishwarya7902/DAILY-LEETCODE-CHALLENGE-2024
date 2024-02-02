PROBLEM :https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02

VIDEO :

/*
  BRUTE FORCE: (GIVES TLE)
  TC:
  SC:

  */

class Solution {
public:
    bool isValid(int nums){
        string s=to_string(nums);
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if(s[i+1]-s[i]!=1)return false;
        }
        return true;
    }
    vector<int> sequentialDigits(int low, int high) {
        vector<int>result;
        for(int i=low;i<=high;i++){
            if(isValid(i))result.push_back(i);
        }

        return result;
    }
};
