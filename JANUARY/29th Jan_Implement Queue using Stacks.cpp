PROBLEM :https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29
VIDEO (MIK BHAIYA): https://www.youtube.com/watch?v=V1vqtGW0X0Y
Problem Name : Implement Queue using Stacks 
Company Tags  : Meta, Amazon, Netflix, Apple, Google, Amazon

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


/*
OPTIMIZATION
TC: Amortized o(1)....what amortized means ...most of the time o(1) hoga ...kabhi kabhi O(n) hoga.
SC:O(N)

*/

class MyQueue {
public:
    stack<int>input;
    stack<int>output;

    int peekEl=-1;

    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){ //if input is empty...it means it will be the first element to enter the queue...
            //we store it in a variable ...so that peek operation can be done in O(1) if output stack is empty
            peekEl=x;
        }
        input.push(x);
        
    }
    //Amortized o(1)
    int pop() {
        if(output.empty()){//input ko output me dalo pahle...O(n)
           while(!input.empty()){
               output.push(input.top());
               input.pop();
           }
           int val=output.top();
           output.pop();
           return val;
        }
       // if output is not empty ...simply pop the first element
        int val=output.top();
           output.pop();
           return val;
        
    }
    
    int peek() {
        if(output.empty())
         return peekEl;
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};

