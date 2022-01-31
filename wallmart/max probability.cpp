double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        unordered_map<int,vector<pair<int,double>>> m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back({edges[i][1],succProb[i]});
            m[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double>  dis(n,0),vis(n);
        dis[start]=1;
        
        priority_queue<pair<double,int>>q;
        q.push({1,start});
        while(!q.empty()){
            auto a = q.top();
            q.pop();
            if(vis[a.second])continue;
            vis[a.second]=1;
            for(auto c:m[a.second]){
                if(!vis[c.first]){
                    if(dis[c.first]<c.second*a.first){
                        dis[c.first]=c.second*a.first;
                        q.push({dis[c.first],c.first});
                    }
                }
            }
        }
        
        return dis[end];
    }

    /*
    in case of min path cost we use BFS traversal so similarly fro prodcut of probability we will apply bfs
    to get maximum probable path
    
    */