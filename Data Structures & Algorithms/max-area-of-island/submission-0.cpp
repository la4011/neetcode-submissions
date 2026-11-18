class Solution {
public:
    bool vis[101][101] = { 0, };
    int hx[4] = { 0,1,0,-1 };
    int hy[4] = { 1,0,-1,0 };
    int ysize;
    int xsize;

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ysize = grid.size();
        xsize = grid[0].size();
        int m = 0;

        for (int i = 0; i < ysize; i++)
            for (int j = 0; j < xsize; j++)
                vis[i][j] = 0;

        for (int i = 0; i < ysize; i++)
            for (int j = 0; j < xsize; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    m = max(m, BFS(i, j, grid));
            }
        return m;
    }

    int BFS(int y, int x, vector<vector<int>> grid)
    {
        queue<pair<int, int>> q;
        q.push({ x,y });
        vis[y][x] = 1;
        int cnt = 1;

        while (!q.empty())
        {
            int bx = q.front().first;
            int by = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = bx + hx[i];
                int ny = by + hy[i];

                if (nx < 0 || ny < 0 || nx >= xsize || ny >= ysize)
                    continue;
                if (vis[ny][nx])
                    continue;
                if (grid[ny][nx] == 0)
                    continue;

                cnt++;
                vis[ny][nx] = 1;
                q.push({ nx,ny });
            }
        }
        return cnt;
    }
};
