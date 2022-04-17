class Solution {
private:
    bool BipartiteDfs(int node,int color[],vector<vector<int>>& graph){
        if(color[node]==-1) color[node] = 1;
        
        for(auto it:graph[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                if(!BipartiteDfs(it,color,graph)){
                    return false;
                }
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int color[n];
        memset(color,-1,sizeof color);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!BipartiteDfs(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};
