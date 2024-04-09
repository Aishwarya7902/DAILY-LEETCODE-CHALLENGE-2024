PROBLEM :https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09
VIDEO:

/*
  BRUTE FORCE:
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    typedef pair<int,int>P;
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<P>que;
        for(int i=0;i<tickets.size();i++){
         que.push({tickets[i],i});
        }
        int time=0;
        while(!que.empty()){
            auto temp=que.front();
            int val=temp.first;
            int indx=temp.second;
            que.pop();

            if(indx==k && val==0){
                return time;
            }

            if(val!=0){
                time++;
                if(indx==k && (val-1)==0){
                return time;
            }
                que.push({val-1,indx});
            }
        }

        return time;
    }
};
