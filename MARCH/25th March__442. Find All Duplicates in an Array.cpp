PROBLEM :https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25

VIDEO:



/*
  BRUTE FORCE (OWN)
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        /*
         story :-
         1.put in map
         2.if freq>1 put in result
        */

        unordered_set<int>mp;
        for(auto &num:nums){
          if(mp.find(num)!=mp.end()){
            result.push_back(num);
          }
          mp.insert(num);
        }

        return result;
    }
};


/*
 APPROACH 2:
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        /*
         story :-
         1.sort
         2.if repeated put in result
        */

        sort(begin(nums),end(nums));//nlogn
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])result.push_back(nums[i]);
        }

        return result;
    }
};

/*
APPROACH 3
TC:O(N)
SC:O(1)
  */

class Solution {
public:
/*
Pattern :
if n sized array and numbers are in range 1 to n
Then there is a hint ❤️
-> USE THE NUMBERS AS INDEX
*/
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>result;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=abs(nums[i]);
            int indx=num-1;

            if(nums[indx]<0)result.push_back(num);
            else 
             nums[indx]*=-1;
        }
        return result;
    }
};
