/*
Problem link: https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = (int)image.size();      // no. of rows
        int m = (int)image[0].size();   // no. of cols
        
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        
        queue<pair<int, int>> qu;
        qu.push({sr, sc});
        vis[sr][sc] = true;
        
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        
        while(!qu.empty())
        {
            pair<int, int> node = qu.front();
            qu.pop();
            int row = node.first;
            int col = node.second;
            image[row][col] = newColor;
            for(int i = 0; i < 4; ++i)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                if((nr < 0) or (nc < 0) or (nr >= n) or (nc >= m) or (vis[nr][nc])) continue;
                
                // vis[nr][nc] must be equal to false if it has reached this point.
                vis[nr][nc] = true;         
                if(image[nr][nc] == oldColor) qu.push({nr, nc});
            }
        }
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends