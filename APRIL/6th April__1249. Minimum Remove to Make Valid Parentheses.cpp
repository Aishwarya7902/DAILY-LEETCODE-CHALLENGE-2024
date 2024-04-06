PROBLEM :

VIDEO :

/*
APPROACH 1
TC:O(N)
SC:O(N) + O(N)
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_set<int>temp;
        int n=s.size();
        // after removing all valid paranthesis......u will be left with index of unvalid ones.
        for(int i=0;i<n;i++){
            if(s[i]=='(')
             st.push(i);
            else if(s[i]==')' && st.empty())temp.insert(i);
            else if(s[i]==')' && !st.empty())st.pop();
        }

        //transfer stack content in set........and then traverse string and if that index is not in set , put it in result

        

        while(!st.empty()){
            temp.insert(st.top());
            st.pop();
        }

        string result="";
       // traverse string and if that index is not in set , put it in result

       for(int i=0;i<n;i++){
         if(temp.find(i)!=temp.end())continue;

         result+=s[i];
       }

       return result;
    }
};

/*
APPROACH 2
  TC:O(N)
  SC:O(N)
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        //iterating left to right (removes extra closing brackets)

        int open=0;
        string result="";

        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                result.push_back(s[i]);
            }

            else if(s[i]=='('){
                open++;
                result.push_back(s[i]);
            }

            else if(open>0){

                open--;
                result.push_back(s[i]);
            }
        }

       //iterating right to left (removes extra opening brackets) 

       int close=0;
       string final_result="";
       for(int i=result.size()-1;i>=0;i--){
        if(result[i]>='a' && result[i]<='z'){
            final_result.push_back(result[i]);
        }
        else if(result[i]==')'){
            close++;
            final_result.push_back(result[i]);
        }

        else if(close>0){
            close--;
            final_result.push_back(result[i]);
        }
       }
       reverse(begin(final_result),end(final_result));
       return final_result;
    }
};
