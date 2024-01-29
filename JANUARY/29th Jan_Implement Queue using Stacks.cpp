PROBLEM :https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29
VIDEO :

/*
BRUTE FORCE (SOLVED ON OWN 💖)
TC: O(N)
SC: O(N)
*/

class MyQueue {
public:
    stack<int>s1;

    stack<int>s2;
    MyQueue() {
       
    }
    
    void push(int x) {
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(x);
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
         while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        return   s2.top();   
        
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

