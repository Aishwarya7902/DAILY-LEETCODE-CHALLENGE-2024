PROBLEM :https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22
VIDEO : https://www.youtube.com/results?search_query=Find+the+Town+Judge

/*
Companies
0 - 6 months
Amazon
2
turing
2
6 months - 1 year
Adobe
2
1 year - 2 years
Apple
3
Bloomberg
2
Walmart Labs
2
Arista
Arista Networks
*/


/*
  APPROACH 1
  u->v means u trust v
  now if arrow is coming then it is indegree...if arrow is going out it is outdegree...
  for town judge indegree should be n-1(coz all rest people trusts him ) and outdegree should be zero (he trusts nobody)
*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>trusts(n+1); //outdegree
        vector<int>trustedBy(n+1); //indegree

        for(auto &vec:trust){
            // u->v
            int u=vec[0];
            int v=vec[1];

            trusts[u]++;
            trustedBy[v]++;
        }

        for(int i=1;i<=n;i++){
            if(trusts[i]==0 && trustedBy[i]==n-1)return i;
        }
        return -1;

    }
};

/*

APPROACH 2
  */

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>Count(n+1); 
        for(auto &vec:trust){
            // u->v
            int u=vec[0];
            int v=vec[1];

            Count[u]--;
            Count[v]++;
        }

        for(int i=1;i<=n;i++){
            if(Count[i]==n-1)return i;
        }
        return -1;

    }
};
