#include<iostream> 
#include<vector> 
#include<stack> 

using namespace std; 

class Solution{
public: 
     
      void dfs(vector<vector<char>>& grid, int r, int c){
        int m = grid.size(); 
        int n = grid[0].size(); 
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]=='0') return; 
        grid[r][c]='0'; 
        dfs(grid, r-1, c); 
        dfs(grid, r+1 , c); 
        dfs(grid, r, c-1); 
        dfs(grid, r, c+1); 
        
      }
      int numberOfIslands(vector<vector<char>>& grid){
        int m = grid.size(); 
        int n = grid[0].size(); 
        int count =0; 

        for(int i=0; i<m; ++i){
          for(int j=0; j<n; ++j){
            if(grid[i][j]=='1'){
              count++; 
              dfs(grid, i, j); 
              
            }
          }
        }
        return count; 
      }
};
int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    Solution sol;
    cout << "Number of islands: " << sol.numberOfIslands(grid) << endl;
    return 0;
}
