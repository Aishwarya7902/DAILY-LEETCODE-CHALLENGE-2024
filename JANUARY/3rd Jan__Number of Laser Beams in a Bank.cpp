PROBLEM :https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/?envType=daily-question&envId=2024-01-03
VIDEO (MIK BHAIYA ):https://www.youtube.com/watch?v=3-c1Gc-5QnE
Company Tags  : Amazon
/*
  TC:O(N)
  SC:O(1)

  */

  class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int result=0;

        int prevDeviceCount=0;
        for(int i=0;i<n;i++){
            int currDeviceCount=0;
            for(char &ch:bank[i])
             {
                 if(ch=='1')
                  currDeviceCount++;
             }

             result+=(currDeviceCount*prevDeviceCount);

             if(currDeviceCount!=0)
              prevDeviceCount=currDeviceCount;
        }
        return result;
    }
};

