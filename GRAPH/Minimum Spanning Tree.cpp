APPROACH #1 Brute Force

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> parent(V,-1);
        vector<int> key(V,INT_MAX);
        vector<bool> mstSet(V,false);
        key[0] = 0;
        parent[0] = -1;
        
        for(int i=0;i<V;i++){
            int u;
            int mini = INT_MAX;
            for(int v=0;v<V;v++){
                if(mstSet[v]==false && key[v]<mini){
                    u=v;
                    mini=key[v];
                }
            }
            mstSet[u] = true;
            
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                if(mstSet[v]==false && weight<key[v]){
                    key[v]=weight;
                    parent[v] = u;
                }
            }
        }
        int sum =0;
        for(int i=0;i<V;i++){
            sum += key[i];
        }
        
        return sum;
    }
};


APPROACH #2 Optimal 

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> parent(V,-1);
        vector<int> key(V,INT_MAX);
        vector<bool> mstSet(V,false);
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        key[0] = 0;
        parent[0] = -1;
        pq.push({0,0});
        
        while(!pq.empty()){
            
            int u=pq.top().second;
            pq.pop();
            
            mstSet[u] = true;
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                if(mstSet[v]==false && weight<key[v]){
                    pq.push({weight,v});
                    key[v]=weight;
                    parent[v] = u;
                }
            }
        }
        int sum =0;
        for(int i=0;i<V;i++){
            sum += key[i];
        }
        
        return sum;
    }
};
