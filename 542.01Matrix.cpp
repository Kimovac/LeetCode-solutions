class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distances(m, vector<int>(n, INT_MAX-1));
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0)
                    distances[i][j] = 0;
                else {
                    if(j > 0)
                        distances[i][j] = min(distances[i][j-1]+1, distances[i][j]);
                    if(i > 0)
                        distances[i][j] = min(distances[i-1][j]+1, distances[i][j]);
                }
            }
        }
        
        for(int i=m-1; i>=0; i--) {
            for(int j=n-1; j>=0; j--) {
                if(j < n-1)
                    distances[i][j] = min(distances[i][j+1]+1, distances[i][j]);
                if(i < m-1)
                    distances[i][j] = min(distances[i+1][j]+1, distances[i][j]);
            }
        }
        
        return distances;
    }
};