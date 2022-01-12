bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
	    
	    for(int i=0;i<prerequisites.size();i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	    }
	    
	    if(detectCycle(adj,N))
	       return false;
	       
	    return true;
	    
	    
	}
	
	bool detectCycle(vector<vector<int>> &adj,int n){
	    
	    vector<int> visited(n,0);
	    
	    for(int i=0;i<n;i++){
	        if(!visited[i]){
	            if(detectCycleUtil(adj,visited,i))
	                return true;
	        }
	    }
	    
	    return false;
	    
	}
	
	bool detectCycleUtil(vector<vector<int>> &adj,vector<int> &visited,int v){
	    if(visited[v]==1)
	       return true;
	   if(visited[v]==2)
	       return false;
	       
	   visited[v]=1;
	   
	   for(int i=0;i<adj[v].size();i++){
	       if(detectCycleUtil(adj,visited,adj[v][i]))
	          return true;
	   }
	   
	   visited[v]=2;
	   
	   return false;
	}

    /*
    visited=0 not visited
    visited=1 unprocessed and visited
    visited=2 processed and visited

    when we get a node of color 2 it means there's no back edge That's why it's not a loop
    but when we get node of color 1 it means there's a back edge and hence cycle.

    0-->1--->2
        \   |
         \  |     in this case node 3 will be colored 2 when node 1 will visit it
          * *     but that doesn't mean there's a cycle bcuzz the direction is 1->3. that's why precessed nodes doesn't form cycle of they come in between.
           3      but if direction was 3->1 then there would be cycle because then node 1 
                will be unpreocessed and hence back edge and thus finds cycle.
    

    cycle detection algo:
    1) iterate on all unvisited node and call helper function for the specific unvisited node one by one.
    2) in helper function check condition of processed and unprocessed nodes
    3) if everything is fine apply dfs like function on the nodes connected to the node passed in the
    helper function.
    4)if everything is fine then color it as processed node and return false.
    
    */