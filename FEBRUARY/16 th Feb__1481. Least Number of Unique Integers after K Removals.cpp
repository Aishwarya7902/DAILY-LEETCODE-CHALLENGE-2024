PROBLEM :https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16
VIDEO:

/*
0 - 6 months
JPMorgan
15
6 months - 1 year
Amazon
2
1 year - 2 years
Booking.com
4
Expedia
2
Dosh
*/


/*
  BRUTE FORCE (SOLVED ON MY OWN)
  ALGO:
  1. Use a map to count the frequencies of the numbers in the array.
  2. An optimal strategy is to remove the numbers with the smallest count first.

  TC: O(nlogn) + O(n)+ O(k)
  SC : O(n) + O(n)

  */

class Solution {
public:
    typedef pair<int,int>P;
    static bool comp(P &a,P &b){
        return a.second>b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      unordered_map<int,int>mp; //SC:O(n)
      vector<P>vec; //SC:O(n)
      for(auto it:arr){ //TC:O(n)
          mp[it]++;
      }

      for(auto it:mp){ //TC:O(n)
          int num=it.first;
          int freq=it.second;

          vec.push_back({num,freq});
      }

      sort(begin(vec),end(vec),comp); //TC:O(nlogn)
      
      while(k>0){ //TC:O(k)
        int i=vec.size()-1;
        if(k>=vec[i].second){
            k-=vec[i].second;
            vec.pop_back();
        }
       else{
           break;
       }
      }

      return vec.size();
    }
};


/*
METHOD 2
WITHOUT SORTING
  */
class Solution {
public:
    typedef pair<int,int>P;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
     unordered_map<int,int>mp; //SC:O(n)
     priority_queue<P,vector<P>,greater<P>>pq; //SC:O(n)


      for(auto it:arr){ //TC:O(n)
          mp[it]++;
      }

      for(auto it:mp){ //TC:O(n)
          int num=it.first;
          int freq=it.second;

          pq.push({freq,num});
      }

      
      
      while(k>0){ //TC:O(k)
        
        if(k>=pq.top().first){
            k-=pq.top().first;
            pq.pop();
        }
       else{
           break;
       }
      }

      return pq.size();
    }
};
