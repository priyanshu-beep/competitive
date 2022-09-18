const int N = 5e3 + 4;

// Four direction move
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


// Eight direction move
// int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
// int dy[8] = {1, -1, -1, 0, 1, -1, 0, 1};


// horse move
// int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
// int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int n, m;
string s[N];
bool vis[N][N];

bool isSafe(int x, int y) {

    if (x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == 0)
        return 1;

    return 0;
}


void dfs(int x, int y){
    vis[x][y] = 1;


    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isSafe(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;


    while (q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isSafe(nx, ny)) {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

    }
}
