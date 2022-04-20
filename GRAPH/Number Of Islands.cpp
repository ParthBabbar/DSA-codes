BFS:

class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0){
            return 0;
        }
        int cols = grid[0].size();
        
        int islands = 0;
        
        queue<pair<int,int>> q;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    q.push({i,j});
                    grid[i][j]='2';
                    while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                        
                    for(auto d : dir ){
                        int rr = r+d[0];
                        int cc= c+d[1];
                        if(rr<0 || cc<0 || rr>=rows || cc>=cols || grid[rr][cc]!='1'){
                            continue;
                        }
                        grid[rr][cc] = '2';
                        q.push({rr,cc});
                    }
                }
            }
          }
            
        }  
        return islands;
    }
        
};


DFS:

class Solution {
private:
    void Current_islands(vector<vector<char>>& grid,int i,int j,int row,int col){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!='1'){
            return ;
        }
        grid[i][j]='2';
        
        Current_islands(grid,i+1,j,row,col);
        Current_islands(grid,i,j+1,row,col);
        Current_islands(grid,i-1,j,row,col);
        Current_islands(grid,i,j-1,row,col);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0){
            return 0;
        }
        int cols = grid[0].size();
        
        int islands = 0;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    Current_islands(grid,i,j,rows,cols);
                    islands += 1;
                }
            }
        }
        return islands;
    }
};
