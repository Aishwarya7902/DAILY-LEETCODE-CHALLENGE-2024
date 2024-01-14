PROBLEM :https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14

VIDEO : https://www.youtube.com/watch?v=KbdCp4nUDiQ
Problem Name : Determine if Two Strings Are Close
Company Tags  : Google, Microsoft, Atlassian, Morgan Stanely, Adobe, Uber

/*
  TC: nlogn
  SC: o(26)
  */


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();

        if(m!=n)return false;

        vector<int>freq1(26);
        vector<int>freq2(26);

        for(int i=0;i<m;i++){
            char ch1=word1[i];
            char ch2=word2[i];

            int indx1=ch1-'a';
            int indx2=ch2-'a';
            freq1[indx1]++;
            freq2[indx2]++;

        }


        //point 1...check if each letter of word1 is present in word2 and vice versa

        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0)continue;
             if(freq1[i]==0 && freq2[i]==0)continue;
            return false;
        }

        //point 2....check if frequency is same for both

        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));

        return freq1==freq2;

    }
};


