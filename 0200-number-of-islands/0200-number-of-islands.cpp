class Solution {
private:
    vector<pair<int,int>> neighbors = 
    {
        {0,-1}, // left
        {0, 1}, // right
        {1,0}, // up 
        {-1,0} //down
    };
public:
    bool validCoord(int newRow, int newCol, int rows, int cols)
    {
        return (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols);
    }
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        stack<pair<int,int>> coordStack;
        coordStack.push({i,j});

        while(!coordStack.empty()) {
            int currentRow = coordStack.top().first;
            int currentCol = coordStack.top().second;
            coordStack.pop();

            // mark as visited
            grid[currentRow][currentCol] = '2'; 

            // push other valid neighbors (left, right, up, down)
            for(int k = 0; k < 4; k++)
            {

                int newRow = neighbors[k].first + currentRow;
                int newCol = neighbors[k].second + currentCol;
                if(validCoord(newRow, newCol, grid.size(), grid[0].size()) && grid[newRow][newCol] == '1')
                {
                    grid[currentRow][currentCol] = '2'; // mark as vistied
                    coordStack.push({newRow, newCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count; 
        
    }
};