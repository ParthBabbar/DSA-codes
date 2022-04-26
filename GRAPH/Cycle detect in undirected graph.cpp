BFS:

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    bool checkCycle(int s,int V, vector<int> adj[],vector<int>& vis){
        vis[s] = true;
        queue<pair<int,int>> q;
        q.push({s,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x] = true;
                    q.push({x,node});
                }
                else if(par != x){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,V,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends



DISJOINT SET(UNION FIND and PATH COMPRESSION) :
 
 
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    struct node{
        int parent;
        int rank;
    };
    
    vector<node> dsuf;
    
    int find(int v){
        if(dsuf[v].parent==-1){
            return v;
        }
        return dsuf[v].parent = find(dsuf[v].parent);
    }
    
    void union_op(int fromP,int toP){
        if(dsuf[fromP].rank > dsuf[toP].rank){
            dsuf[toP].parent = fromP;
        }
        else if(dsuf[fromP].rank < dsuf[toP].rank){
            dsuf[fromP].parent = toP;
        }
        else{
            dsuf[fromP].parent = toP;
            dsuf[toP].rank += 1;
        }
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        dsuf.resize(V);
        for(int i=0;i<V;i++){
            dsuf[i].parent= -1;
            dsuf[i].rank = 0;
        }
        
        vector<int> v(V,0);
        for(int i=0;i<V;i++){
            v[i]++;
            for(auto j:adj[i]){
               if(v[j]) continue;
               int a=find(i),b=find(j);
               if(a==b) return true;
               union_op(a,b);
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
