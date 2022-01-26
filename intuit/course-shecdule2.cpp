class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        
        for(int i=0;i<n;i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        vector<int> ans;
        if(detectCycle(adj,numCourses))
            return ans;
        
        stack<int> mystack;
        vector<bool> visited(numCourses,false);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                dfs(adj,i,visited,mystack);
        }
        
        while(!mystack.empty()){
            ans.push_back(mystack.top());
            mystack.pop();
        }
        
        return ans;
        
        
    }
    
    void dfs(vector<vector<int>>& adj,int v,vector<bool>& visited,stack<int>& mystack){
        visited[v]=true;
        for(int i=0;i<adj[v].size();i++){
            if(!visited[adj[v][i]]){
                 dfs(adj,adj[v][i],visited,mystack);
             }
        }
        
        mystack.push(v);
    }
    
    bool detectCycle(vector<vector<int>>& adj,int n){
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(detectCycleUtil(adj,visited,i))
                  return true;
            }
        }
        return false;
    }
    //graph coloring :---- 0:not visted , 1:visited  , 2: processed
    bool detectCycleUtil(vector<vector<int>>& adj,vector<int> &visited,int v){
        
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
};

/*
 topologoical sort for returning the answer in the order of completeing course 
 before topological sorting detect if there's a cycle 

*/