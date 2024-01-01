PROBLEM : https://leetcode.com/problems/assign-cookies/description/?envType=daily-question&envId=2024-01-01
VIDEO (MIK BHAIYA):  https://www.youtube.com/watch?v=oyzF9AsOUQ8
Company Tags    : Amazon, Meta

/*
LESSON 💖
Ek min greed wale bache pe ek badi size ka cookie waste karna bewakoofi hogi na
*/



/*
BRUTE FORCE : DID ON MY OWN 😎
TC: O(nlogn + mlogm)
SC:

*/

class Solution {
public:
    int   canSatisfy(int target, vector<int>& arr){
       
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=target)return i;
        }

        return -1;
    }
    int findContentChildren(vector<int>& greed, vector<int>& size) {
        int  result=0;
        //u need to sort both the greed and size because we have to delete elements of size once we get a meeting condition
        sort(begin(greed),end(greed));
        sort(begin(size),end(size));
        for(int i=0;i<greed.size();i++){
            if(canSatisfy(greed[i],size)!=-1){
                int indx=canSatisfy(greed[i],size);
                //once u meet satisfying condition give that cookie to the child and delete it.
                size.erase(size.begin()+indx);
                result++;
            }
        }
        return result;
    }
};


/*
OPTIMISATION
//T.C : O(mlogm + nlogn)
//S.C : O(1)
*/

class Solution {
public:

    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(begin(g),end(g));
        sort(begin(s),end(s));
        int m=g.size();
        int n=s.size();
        
        int i=0,j=0;
        while(i<m && j<n){
            if(g[i]<=s[j])i++;
            j++;
        }
       return i; 
    }
};
