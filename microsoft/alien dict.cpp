 void dfs(int v,vector<vector<int>> adj,vector<int>&vis,vector<int> &topo){
        vis[v]=1;
        
        for(auto i:adj[v]){
            if(!vis[i])
             dfs(i,adj,vis,topo);
        }
        
        topo.push_back(v);
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>> adj(K);
        for(int i=1;i<N;i++){
            string s1=dict[i-1];
            string s2=dict[i];
            
            for(int j=0;j<min(s1.size(),s2.size());j++){
                if(s1[j]!=s2[j]){
                    int u =s1[j]-'a';
                    int v=s2[j]-'a';
                    //cout<<"h"<<u<<v;
                    adj[u].push_back(v);
                    break;
                }
            }
        }
            
            
            vector<int> vis(K,0);
            vector<int> topo;
            
            for(int i=0;i<K;i++){
                if(!vis[i]){
                    dfs(i,adj,vis,topo);
                }
            }
            
            reverse(topo.begin(),topo.end());
            
            string ans="";
            
            for(auto i:topo){
                ans+=i+'a';
            }
            //cout<<ans;
            return ans;
        
    }

    /*
    Topological sorting for Directed Acyclic Graph (DAG) is a linear
    ordering of vertices such that for every directed edge u v, vertex u comes before v
    in the ordering. (e.g prerequisite courses order)

    so using adjacency list we are storing which alphabet comes first in the list.
    we are making edges between two neighbouring dictionary string's alphabet where they differ.
    e.g.  aab aac  it means b comes before c (b->c).


    topological sort:
    we have to push in stack all the connected nodes of the edge first
    and at last we will enter the node whose all connected nodes are
    already in the stack.

    to get the order we pop the elements of the stack .

    dfs and topological sort is different becuase in dfs we print the node first and then it's adjacent
    nodes. 
    we take help of dfs to find out topological order.
    
    
    
    
    */