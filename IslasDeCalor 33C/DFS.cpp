#include "DFS.hpp"

Point::Point()
{
    temp = -999;
    isVisited = false;
    isLand = false;
};

// These arrays are used to get
// r and c numbers of 8
// neighbours of a given cell
static vector<int> rNbr = { -1, -1, -1, 0, 0, 1, 1, 1 };
static vector<int> cNbr = { -1, 0, 1, -1, 1, -1, 0, 1 };

// A function to check if a given
// cell (r, c) can be included in DFS
bool isSafe(const vector<vector<Point*>> &grid, int r, int c) {
    int row = grid.size();
    int col = grid[0].size();

    if ((r < 0) || (r >= row) || (c < 0) ||
        (c >= col)) return false;
    if (grid[r][c] == nullptr) { return false; };
    // r is in range, c is in range, value 
    // is 'L' (land) and not yet visited
    return (grid[r][c]->isLand) && (!grid[r][c]->isVisited);

}

// A utility function to do DFS for a
// 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void dfs(vector<vector<Point*>>& grid, int r, int c, int depth) {

    // Mark this cell as visited
    grid[r][c]->isVisited = true;

    if (depth == 0) return;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k) {
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];

        if (isSafe(grid, newR, newC)) {
            dfs(grid, newR, newC,depth-1);
        }
    }
}

// The main function that returns
// count of islands in a given boolean
// 2D matrix
int countIslands(vector<vector<Point*>> &grid) {
    int row = grid.size();
    int col = grid[0].size();

    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    //vector<vector<bool>> visited(row, vector<bool>(col, false));

    // Initialize count as 0 and traverse through
    // all cells of the given matrix
    int count = 0;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {

            // If a cell with value 'L' (land) is not visited yet,
            // then a new island is found

            if (grid[r][c] == nullptr) continue;

            if ((grid[r][c]->isLand) && !(grid[r][c]->isVisited)) {

                // Visit all cells in this island.
                dfs(grid, r, c,16000);

                // Increment the island count
                ++count;
            }
        }
    }
    return count;
}