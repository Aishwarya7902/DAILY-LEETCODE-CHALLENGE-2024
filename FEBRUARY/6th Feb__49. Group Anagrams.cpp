PROBLEM :https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06

VIDEO (MIK BHAIYA): 
1.SORTING : https://www.youtube.com/watch?v=TNe3gF4r128
2.WITHOUT SORTING :


/*

BRUTE FORCE (GIVING TLE )......SOLVED ON  OWN
*/

class Solution {
public:
    bool isAnagram(string s1,string s2){
        //TC :O(nlogn)
        sort(begin(s1),end(s1));
        sort(begin(s2),end(s2));
        return s1==s2;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       int n=strs.size();
       if(n==0)return {{}};
       vector<vector<string>>result;

       vector<int>vis(n,-1);
       //TC :O(n)...since we are visiting each index once
       //SC: O(n)...vis vector +O(n)...curr vector
       for(int i=0;i<n;i++){
           if(vis[i]!=-1)continue;
           vector<string>curr;
           curr.push_back(strs[i]);
           vis[i]=1;

           for(int j=i+1;j<n;j++){
               if(vis[j]!=-1)continue;
               if(isAnagram(strs[i],strs[j])){
                   curr.push_back(strs[j]);
                   vis[j]=1;
               }
           }
           result.push_back(curr);

       }

    return result;

    }

};

/*
BETTER APPROACH
TC:O(n*klogk) ....n is size of strs and k is the max size of any string


*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>result;
        int n=strs.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++){
           string temp=strs[i];
           sort(begin(temp),end(temp));
           mp[temp].push_back(strs[i]);
        }

        for(auto it:mp){
            result.push_back(it.second);
        }
       
        return result;
    }
};
