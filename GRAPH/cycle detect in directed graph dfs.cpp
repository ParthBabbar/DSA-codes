// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    bool checkCycle(int node,int vis[],int dfsvis[], vector<int> adj[]){
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto i:adj[node]){
            if(!vis[i]){
                if(checkCycle(i,vis,dfsvis,adj)){
                    return true;
                }
            }
            else if(dfsvis[i]){
                return true;
            }
        }
        
        dfsvis[node]=0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V], dfsvis[V];
        memset(vis,0,sizeof vis);
        memset(dfsvis,0,sizeof dfsvis);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,vis,dfsvis,adj)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
