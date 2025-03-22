class Solution {
    bool bfs(vector<vector<int>> &adj, vector<bool> &vis, int n){
        int edges = 0 , vertices = 0 ;
        queue<int> q ;
        q.push(n) ;
        vis[n] = true ;
        while(!q.empty()){
            int u = q.front() ;
            ++vertices ;
            q.pop() ;
            for(int v : adj[u]){
                ++edges ;
                if(vis[v]) continue ;
                vis[v] = true ;
                q.push(v) ;      
            }
        }
        edges /= 2 ;
        return (vertices*(vertices-1))/2 == edges ;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n) ;
        for(auto &e : edges){
            adj[e[0]].push_back(e[1]) ;
            adj[e[1]].push_back(e[0]) ;
        }
        vector<bool> vis(n,false) ;
        int cnt = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(vis[i]) continue ;
            cnt += bfs(adj,vis,i) ;
        }
        return cnt ;
    }
};