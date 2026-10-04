class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == '1') {
                    islands++;

                    queue<pair<int, int>> q;
                    q.push({i, j});

                    // marchez vizitat
                    grid[i][j] = '0';

                    while(!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();

                        for(int d = 0; d < 4; d++) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if(nr >= 0 && nr < rows &&
                               nc >= 0 && nc < cols &&
                               grid[nr][nc] == '1') {

                                grid[nr][nc] = '0';
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};