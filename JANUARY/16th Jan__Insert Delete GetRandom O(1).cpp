PROBLEM :https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16
VIDEO (MIK BHAIYA):https://www.youtube.com/watch?v=3yTnLrNdJGo

Problem Name : Insert Delete GetRandom O(1) (Leetcode 380)
Company Tags  : Amazon, Twitter, Facebook, Uber, Google, Bloomberg, Microsoft

/*
  tc:
  sc:

*/

  class RandomizedSet {
public:
    vector<int>vec;
    unordered_map<int,int>mp;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())return false;

        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;
        
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;

        int indx=mp[val];//access the indx of element which we have to delete

        int lastElement=vec.back();
        //swap val and lastElement
        vec.back()=val;
        vec[indx]=lastElement;

        //remove val from map and vec;
        vec.pop_back();
        mp.erase(val);

        mp[lastElement]=indx;
        return true;
        
    }
    
    int getRandom() {
        int n=vec.size();
        int randomIndx=rand()%n;
        return vec[randomIndx];
    }
};

