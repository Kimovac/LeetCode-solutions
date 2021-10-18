class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int, int>> rotten;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2)
                    rotten.push(make_pair(i, j));
            }
        }
        
        //seperates rotten oranges from
        //new rotten oranges
        rotten.push(make_pair(-1, -1));
        
        int mins = 0;
        while(!rotten.empty()) {
            bool first_fresh = false;
            
            auto tmp = rotten.front();
            while(tmp.first != -1) {
                if(tmp.first > 0 && grid[tmp.first-1][tmp.second] == 1) {
                    if(!first_fresh) {
                        mins++;
                        first_fresh = true;
                    }
                    grid[tmp.first-1][tmp.second] = 2;
                    rotten.push(make_pair(tmp.first-1, tmp.second));
                }
                
                if(tmp.first < m-1 && grid[tmp.first+1][tmp.second] == 1) {
                    if(!first_fresh) {
                        mins++;
                        first_fresh = true;
                    }
                    grid[tmp.first+1][tmp.second] = 2;
                    rotten.push(make_pair(tmp.first+1, tmp.second));
                }
                
                if(tmp.second > 0 && grid[tmp.first][tmp.second-1] == 1) {
                    if(!first_fresh) {
                        mins++;
                        first_fresh = true;
                    }
                    grid[tmp.first][tmp.second-1] = 2;
                    rotten.push(make_pair(tmp.first, tmp.second-1));
                }
                
                if(tmp.second < n-1 && grid[tmp.first][tmp.second+1] == 1) {
                    if(!first_fresh) {
                        mins++;
                        first_fresh = true;
                    }
                    grid[tmp.first][tmp.second+1] = 2;
                    rotten.push(make_pair(tmp.first, tmp.second+1));
                }
                
                rotten.pop();
                tmp = rotten.front();
            }
            
            rotten.pop();
            if(!rotten.empty())
                rotten.push(make_pair(-1, -1));
        }
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return mins;
    }
};