  class Solution{
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V+1, false);
        vector<int> ans;
         queue<int> q;
    visited[0]=true;
    q.push(0);
    while(!q.empty())
    {
        auto u= q.front();
        q.pop();
        ans.push_back(u);
        for(auto v: adj[u])
        {
            if(visited[v]==false)
            {
                   visited[v]=true;
                   q.push(v);
            }
        }
    }
    return ans;
    }
};
