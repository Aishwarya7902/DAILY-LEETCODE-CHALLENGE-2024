PROBLEM : https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

VIDEO :https://www.youtube.com/watch?v=oGPfmp71Zm4
/*
Companies
0 - 6 months
Facebook
45
Amazon
4
Apple
2
1 year - 2 years
Google
3
Bloomberg
3
Uber
2
TikTok
2

*/

/*
  METHOD 1
  T.C : O(m+n)
  S.C : O(26) ~ O(1)
*/

class Solution {
public:
    string customSortString(string order, string s) {
        int count[26]={0};
        //storing freq of each char of s
        for(auto &ch:s){
            count[ch-'a']++;
        }

        string result="";
       // which ever char of order are in s put in result
        for(auto &ch:order){
            while(count[ch-'a']--){
                result.push_back(ch);
            }
        }

        for(auto &ch:s){
            if(count[ch-'a']>0)result.push_back(ch);
        }
    
     return result;
    }
};

/*
METHOD 2
TC: O(nlogn)
SC:O(1)
  */

class Solution {
public:
    string customSortString(string order, string s) {

        vector<int>mp(26,-1);
        for(int i=0;i<order.size();i++){
           mp[order[i]-'a']=i;
        }
        auto myComparator=[&mp](char &ch1,char &ch2){
            return mp[ch1-'a']<mp[ch2-'a'];
        };
        sort(begin(s),end(s),myComparator);
        return s;
    }
};


/*What was actually asked in Facebook :
FOLLOW UP NOTE : The original questions that was asked by Facebook was similar to
this but there was one small variation that "The characters which don't
occur in "str" must be sorted as per English Alphabet order".  In that case
one slight change will do the job in comparator function below :
*/
class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> index(26, INT_MAX);
        
        for(int i = 0; i<order.length(); i++)
            index[order[i]-'a'] = i;
        
        
        auto lambda = [&](char &ch1, char &ch2) {
            if(index[ch1-'a'] == index[ch2-'a'])
                return ch1 < ch2;
            
            return index[ch1-'a'] < index[ch2-'a'];
        };
        
        sort(begin(str), end(str), lambda);
        return str;
        
    }
};
  
