#include<iostream> 
#include<stack> 
#include<vector> 

using namespace std; 

class Solution{
public: 
      int numberOfIslands(vector<vector<char>>& grid){
        int m = grid.size(); 
        int n = grid[0].size(); 

        vector<int> direction = {-1,0,1,0,-1}; 
        int count = 0; 

        for(int i=0; i<m; ++i){
          for(int j=0; j<n; ++j){
            if(grid[i][j]=='1'){
              stack<pair<int,int>> st; 
              st.push({i,j}); 
              count++; 
              grid[i][j] = '0'; 
              while(!st.empty()){
                auto [x,y] = st.top(); 
                st.pop(); 
                for(int k=0; k<4; ++k){
                  int dx = x+direction[k]; 
                  int dy = y+ direction[k+1]; 
                  if(dx >=0 && dx<m && dy>=0 && dy<n && grid[dx][dy]=='1'){
                    st.push({dx,dy}); 
                    grid[dx][dy]='0'; 
                  }
                }
              }
            }
          }
        }
        return count; 
          
      }
};

int main(){
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
