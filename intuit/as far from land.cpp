class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        
         queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }else{
                    grid[i][j]=-1;
                }
            }
        }
        
        if(q.empty() || q.size()==grid.size()*grid[0].size()){
            return -1;
        }
        
        int depth=-1;
        
        while(!q.empty()){
            int len=q.size();
            
            for(int i=0;i<len;i++){
                pair<int,int> p =q.front();
                if(p.first+1 < grid.size() && grid[p.first+1][p.second]==-1 ){
                    q.push({p.first+1,p.second});
                    grid[p.first+1][p.second]=2;
                    
                }
                
                if(p.first-1 < grid.size() && grid[p.first-1][p.second]==-1  ){
                    q.push({p.first-1,p.second});
                    grid[p.first-1][p.second]=2;
                }
                
                if(p.second+1 <grid[0].size() && grid[p.first][p.second+1]==-1   ){
                    q.push({p.first,p.second+1});
                    grid[p.first][p.second+1]=2;
                }
                
                if(p.second-1 < grid[0].size() && grid[p.first][p.second-1]==-1  ){
                    q.push({p.first,p.second-1});
                    grid[p.first][p.second-1]=2;
                }
                
                q.pop();
            }
            ++depth;
        }
        
        return depth;
    }
};

/*
classic BFS problem 

*/