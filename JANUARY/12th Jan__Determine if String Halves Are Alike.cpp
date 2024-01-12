//PROBLEM:
//VIDEO:
class Solution {
private:
  int helpCountVowels(string s,int start,int end){
    int count_vowels=0;
    set<char>st({'a','e','i','o','u','A','E','I','O','U'});
    for(int index=start;index<end ;index++){
      if(st.find(s[index])!=st.end())
        count_vowels++;
    }
    return count_vowels++;
  }
  
  
public:
    bool halvesAreAlike(string s) {
        int total_size=s.size();
        int size_of_each=total_size/2;
        int count_vowels_a=helpCountVowels(s,0,size_of_each);
        int count_vowels_b=helpCountVowels(s,size_of_each,total_size);
      return count_vowels_a==count_vowels_b;
        
    }
};
