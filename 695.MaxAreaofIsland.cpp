class Solution {
public:
    int island_size(vector<vector<int>> &grid, int i, int j) {
        int size = 1;
        grid[i][j] = -1;
        
        if(j-1 >= 0 && grid[i][j-1] == 1)
            size += island_size(grid, i, j-1);
        
        if(j+1 < grid[0].size() && grid[i][j+1] == 1)
            size += island_size(grid, i, j+1);
        
        if(i-1 >= 0 && grid[i-1][j] == 1) 
            size += island_size(grid, i-1, j);
        
                    
        if(i+1 < grid.size() && grid[i+1][j] == 1)
            size += island_size(grid, i+1, j);
        
        return size;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_size = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    max_size = max(max_size, island_size(grid, i, j));
                }
            }
        }
        
        return max_size;
    }
};