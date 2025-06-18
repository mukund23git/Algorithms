class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        //creating adj list
        
        //create adj list
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        
        set<pair<int,int>>st;
        vector<int> dis(V, 1e9);
        
        dis[src] = 0;
        st.insert({0 , src});
        
        while(!st.empty()){
            auto it = *(st.begin());
            
            int node = it.second;
            int dist = it.first;
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                int Wt = it.second;
                
                if(dis[adjNode] > dist + Wt){
                    
                    if(dis[adjNode] != 1e9){
                        st.erase({dis[adjNode] , adjNode});
                    }
                    
                    dis[adjNode] = dist + Wt;
                    st.insert({dis[adjNode] , adjNode});
                }
            }
        }
        
        return dis;
        
        
        
            
    }
    
};
