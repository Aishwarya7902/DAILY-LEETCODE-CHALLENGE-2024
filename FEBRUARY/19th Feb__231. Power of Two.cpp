PROBLEM : https://leetcode.com/problems/power-of-two/description/?envType=daily-question&envId=2024-02-19

VIDEO : 

/*
Companies
0 - 6 months
Amazon
5
Adobe
3
Bloomberg
3
6 months - 1 year
Snapchat
2
1 year - 2 years
Apple
8
Google
3
General Motors
3
Uber
2
Qualcomm
2
JPMorgan
2

*/


/*
  BRUTE FORCE
  TC : O(N)
  SC : O(1)
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        while(n>1){
            cout<<n<<endl;
            if(n%2!=0)return false;
            n/=2;
        }
        return n==1;
    }
};
