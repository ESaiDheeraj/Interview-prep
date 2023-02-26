/*
Problem link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Initially all vertices are marked as not visited
        vector<bool> vis(V, false);
        
        vector<int> ans;
        
        // A queue is used to do the level order travel (breadth first search)
        queue<int> qu;
        qu.push(0);
        vis[0] = true;
        
        while(!qu.empty())
        {
            int front = qu.front();
            qu.pop();
            ans.push_back(front);
            for(int node: adj[front])
            {
                if(!vis[node]) 
                {
                    vis[node] = true;
                    qu.push(node);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
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
            // 		adj[v].push_back(u);
        }
        
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends