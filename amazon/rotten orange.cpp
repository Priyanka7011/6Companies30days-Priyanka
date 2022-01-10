int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        
        int depth=0;
        
        while(!q.empty()){
            int len = q.size();
            
            for(int i=0;i<len;i++){
                
                pair<int,int> p = q.front();
                
                if(p.first+1 < grid.size() && grid[p.first+1][p.second]==1 ){
                    q.push({p.first+1,p.second});
                    grid[p.first+1][p.second]=-1;
                }
                if(p.first-1 < grid.size() && grid[p.first-1][p.second]==1){
                    q.push({p.first-1,p.second});
                    grid[p.first-1][p.second]=-1;
                }
                if(p.second+1 < grid[0].size() && grid[p.first][p.second+1]==1){
                     q.push({p.first,p.second+1});
                    grid[p.first][p.second+1]=-1;
                }
                if(p.second-1 < grid[0].size() && grid[p.first][p.second-1]==1){
                     q.push({p.first,p.second-1});
                    grid[p.first][p.second-1]=-1;
                }
                
                q.pop();
                
            }
            
            ++depth;
            //cout<<depth;
        }
        
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count!=0)
            return -1;
        else if(depth==0)
            return 0;
        else
            return depth-1;
        
    }

    /*
    we used bfs traversal as we have to find minimum time in which all oranges will be rotten.

    first we push all the rotten elements in the queue.
    then we check in 4 directions for all the values in queue.
    pop out the value from queue if it's already considered.
    increase the depth
    depth-1 is the answer because it is incrementing one extra.
    
    
    */