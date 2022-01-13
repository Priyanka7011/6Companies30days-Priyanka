int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int ans=0;
        int max_area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    max_area=max(dfs(grid,i,j),max_area);
                }
            }
        }
        
        
        
        
        
        return max_area;
    }
    
    int dfs(vector<vector<int>>& grid,int r,int c){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size()){
            return 0;
        }
        if(grid[r][c]!=1){
            return 0;
        }
        grid[r][c]=-1;
        
        return 1+dfs(grid,r+1,c) +
        dfs(grid,r,c+1)+
        dfs(grid,r-1,c)+
        dfs(grid,r,c-1)+
        dfs(grid,r-1,c+1)+
        dfs(grid,r-1,c-1)+
        dfs(grid,r+1,c+1)+
        dfs(grid,r+1,c-1);
        
        
    }

    /*
    we have to find different connected group of 1's and report maximum of it.
    so if i will simply convert visite 1 with -1 and then count then i will get 
    total no. of 1's not connected 1's
    
    */