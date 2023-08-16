class node{
    public: 
    int x = 0, y = 0,time = 0;
    node(int x,int y,int time){
        this->x = x;this->y = y;this->time = time;
    }
};
class Solution {
public:
     int bfs(vector<vector<int>>& grid, queue<node>q,map<pair<int,int>,bool>&visited,int totalfresh){
        int n = grid.size();
        int MinTime = 0;
        while(!q.empty()){
            auto fnode = q.front();
            int x = fnode.x, y = fnode.y, time =fnode.time;
            MinTime = time;
            q.pop();

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
    
            for(int i = 0 ;i< 4;i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx >= 0 && newy >= 0  && newx < n && newy < grid[0].size() && 
                grid[newx][newy] == 1 && visited[{newx,newy}] == false ){
                    node n(newx,newy,time+1);
                    q.push(n);
                    visited[{newx,newy}] = true;
                    totalfresh--;
                }
            }
        }
        if(totalfresh > 0) return -1;
        return MinTime;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        map<pair<int,int>,bool>visited;
        queue<node>q;
        int TotalFresh = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2 && !visited[{i,j}]){
                    node n(i,j,0);
                    q.push(n);
                    visited[{i,j}] = true;
                }
                if(grid[i][j] == 1 ) TotalFresh++;
            }
        }
        return bfs(grid,q,visited,TotalFresh);
    }
};