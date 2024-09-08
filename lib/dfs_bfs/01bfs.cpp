#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
 * 01-bfs
 * 辺の重みが0か1であるグラフの最短距離を求める.
 * ・bfs => FIFO
 * ・01-bfs => 辺の重みが0なら先頭に挿入, 1なら末尾に挿入.
 * O(E) : E => 辺の数.
 * 
*/


// 例：ARC05 C

int H, W, N;
char c[510][510];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sx, sy;

int bfs_01(int x, int y) {
    deque<tuple<int, int, int> > deq;
    bool visited[H][W];
    memset(visited, false, sizeof(visited));
    visited[x][y] = true;
    deq.push_back(make_tuple(x, y, 0));

    while (!deq.empty()) {
        tuple<int, int, int> tp = deq.front();
        deq.pop_front();

        int nx = get<0>(tp);
        int ny = get<1>(tp);
        int walls = get<2>(tp);

        if (c[nx][ny] == 'g') {
            sx = nx;
            sy = ny;
            return walls;
        }

        for (int i = 0; i < 4; i++) {
            if (0 <= nx+dx[i] && nx+dx[i] < H && 0 <= ny+dy[i] && ny+dy[i] < W) {
                if (visited[nx+dx[i]][ny+dy[i]] == false) {
                    if (c[nx+dx[i]][ny+dy[i]] == '#') {
                        visited[nx+dx[i]][ny+dy[i]]= true;
                        deq.push_back(make_tuple(nx+dx[i], ny+dy[i], walls+1));
                    }
                    else {
                        visited[nx+dx[i]][ny+dy[i]]= true;
                        deq.push_front(make_tuple(nx+dx[i], ny+dy[i], walls));
                    }
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c[i][j];
            if (c[i][j] == 's') {
                sx = i;
                sy = j;
            }
        }
    }

    int break_walls = bfs_01(sx, sy);

    if (break_walls <= 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
