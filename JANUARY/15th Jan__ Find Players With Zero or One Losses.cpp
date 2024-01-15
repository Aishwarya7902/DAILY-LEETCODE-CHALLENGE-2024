PROBLEM :https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15
VIDEO (MIK BHAIYA):

/*

  BRUTE FORCE (DONE BY SELF)
  TC: o(nlogn)
  SC: o(n)

*/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        

        //take two maps...one for winner and one for losers

        unordered_map<int,int>winners; //sc:o(n)
        unordered_map<int,int>losers; //sc:o(n)

        //step 1 ...travel in matches
        for(auto &vec:matches){ //tc:o(n)
            int winnerPerson=vec[0];
            int loserPerson=vec[1];
            winners[winnerPerson]++;
            losers[loserPerson]++;

        }

        //take a ans vector
        vector<vector<int>>answer;
        //take a vector to store people did not lost any match
        vector<int>LostNoMatch; //sc:o(n)
        //take a vector to store people who lost exaclty one match

        vector<int>LostExactlyOneMatch; //sc:o(n)
        //step 2:traverse in winner map and if that key is not present in loser map...it means that person has not lost any match ...so we keep it 

        for(auto it:winners){
            int key=it.first;
            if(losers.find(key)==losers.end()){
                LostNoMatch.push_back(key);
            }
        }

        sort(begin(LostNoMatch),end(LostNoMatch)); //nlogn
        answer.push_back(LostNoMatch);

        //traverse in losers map...and if it has lost exactly one match....we keep it

        for(auto &it:losers){
            int key=it.first;
            if(it.second==1){
                LostExactlyOneMatch.push_back(key);

            }
        }

        sort(begin(LostExactlyOneMatch),end(LostExactlyOneMatch)); //nlogn

        answer.push_back(LostExactlyOneMatch);

        return answer;

    }
};
