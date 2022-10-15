class Solution {
public:
    bool ispos(int a,int b,int m,int n,vector<vector<int>>& grid){
        if(a<0||a>=m||b<0||b>=n){
            return false;
        }
        if(grid[a][b]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int ans=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                 for(int i=0;i<4;i++){
                     if(ispos(it.first+dx[i],it.second+dy[i],grid.size(),grid[0].size(),grid)){
                         grid[it.first+dx[i]][it.second+dy[i]]=2;
                         q.push({it.first+dx[i],it.second+dy[i]});
                     }
                     
                 }
            }
            ans++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return (ans==-1)?0:ans;
    }
};
