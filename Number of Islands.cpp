class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                  help(grid,i,j);
                      ans++;  
                }
            }
        }
        return ans;
    }
    void help(vector<vector<char>>& grid,int i, int j){
        if(i<0||j<0||i==grid.size()||j==grid[0].size()||grid[i][j]=='0')
            return;
        grid[i][j]='0';
        help(grid,i+1,j);
        help(grid,i,j+1);
        help(grid,i-1,j);
        help(grid,i,j-1);
    }
};
