PROBLEM :https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

VIDEO (MIK BHAIYA) :

/*
BRUTE FORCE (SOLVED ON MY OWN 💖😎)

TC:
SC:
*/

class Solution {
public:
    int solve(string token,int a,int b){
        if(token=="+")return a+b;
        else if(token=="-")return a-b;
        else if(token=="/")return a/b;
        return a*b;
    }

    
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if( (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="*") &&!st.empty()){
                int second=st.top();
                st.pop();
                int first=st.top();
                st.pop();
                int result=solve(tokens[i],first,second);
                st.push(result);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
