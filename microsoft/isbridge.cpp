void dfs(int x,vector<int> adj[],vector<int> &vis,int c,int d){
        vis[x]=1;
        for(auto i:adj[x]){
            if(x==c && i==d) continue;
            if(!vis[i])
            dfs(i,adj,vis,c,d);
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V,0);
        
        dfs(c,adj,vis,c,d);
        
        return(!vis[d]);
    }


/*
we can prove if the undirected graph is connected or not by checking  on traversing whether
we visited every node.

so here we applied dfs starting from any node.

after that according to question we had to remove an edge and then check if graph is connected or not.
so we just skipped that edge when it appeared in the adjacency list , no need to delete it.

and to prove that graph is connected after removing edge between c and d
we just checked the visit status of node d.
if node  d is visited it means that there's some other edge which can lead us to node d.
but if node d is not visited then it means there was only one edge to reach d
which was between c and d , because we removed that edge now we can't reach d and hence it's



*/