class Solution {
public:
    int totalPaths = 0;
    int totalCells = 0;

    void uniPaths(vector<vector<int>>& g, int i, int j, int vis) {
        int n = g.size();
        int m = g[0].size();

        // Out of bounds or obstacle
        if(i < 0 || j < 0 || i >= n || j >= m || g[i][j] == -1)
            return;

        // Reached the end square
        if(g[i][j] == 2) {
            if(vis == totalCells)
                totalPaths++;
            return;
        }

        // Mark current cell as visited
        int o = g[i][j]; // could be 0 or 1
        g[i][j] = -1;

        // Explore all 4 directions
        uniPaths(g, i + 1, j, vis + 1);
        uniPaths(g, i - 1, j, vis + 1);
        uniPaths(g, i, j + 1, vis + 1);
        uniPaths(g, i, j - 1, vis + 1);

        // Backtrack: Unmark current cell
        g[i][j] = o;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0;
        int n = grid.size(), m = grid[0].size();
        // Find start and count non-obstacle cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] != -1) totalCells++;
                if(grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        }
        uniPaths(grid, startX, startY, 1); // start with 1 cell already visited
        return totalPaths;
    }
};