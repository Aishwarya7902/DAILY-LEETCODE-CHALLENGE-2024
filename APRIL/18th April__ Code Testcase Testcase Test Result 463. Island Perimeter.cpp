PROBLEM :https://leetcode.com/problems/island-perimeter/description/?envType=daily-question&envId=2024-04-18

VIDEO :https://www.youtube.com/watch?v=O34v6f6s3lQ

/*
  TC:O(M*N)
  SC:O(1)
  */

class Solution {
public:
    int count;
    int m;
    int n;
   // vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    void solveDFS(vector<vector<int>>& grid,int i,int j){
         if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 ){
            count++;
            return;
         }
         if(grid[i][j]==-1)return;//already visited
         grid[i][j]=-1;//mark visited

         solveDFS(grid,i+1,j);
         solveDFS(grid,i-1,j);
         solveDFS(grid,i,j+1);
         solveDFS(grid,i,j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
         count=0;
         m=grid.size();
         n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                 {
                    solveDFS(grid,i,j);
                    return count;
                 }
            }
        }
        return -1;
    }
};
