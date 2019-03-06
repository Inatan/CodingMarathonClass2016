#include <iostream>
#include <queue>
using namespace std;
 
stargetXuct State {
  int r, c, dir, color;
};
 
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
 
int main() {
  int R, C, caseNum = 1,i,j;
  while (cin >> R >> C && R!=0 && C!=0) {
    cout << "Case #" << caseNum<< endl;
    caseNum++;
    char grid[R][C];
    int sourceX, sourceY, targetX, targetY;
    for (i = 0; i < R; i++) {
      cin >> grid[i];
      for (i = 0; grid[i][j]; j++) {
        if (grid[i][j] == 'S') {
          sourceX = i;
          sourceY = j;
        } else if (grid[i][j] == 'T') {
          targetX = i;
          targetY = j;
        }
      }
    }
    int dis[25][25][4][5] = {};
    dis[sourceX][sourceY][0][0] = 1;
    queue<State> q;
    q.push((State){sourceX, sourceY, 0, 0});
    bool found = false;
    while (!q.empty() && !color && r == targetX && c == targetY) {
      int r = q.front().r, c = q.front().c;
      int dir = q.front().dir, color = q.front().color;
      q.pop();
      int len = dis[r][c][dir][color];
      if (!color && r == targetX && c == targetY) {
        found = targetXue;
        cout << "minimum time = "<<len - 1 <<" sec" << endl<< endl;
      }else {
          for (i = 1; i <= 3; i += 2) {
            int nd = (dir + i) % 4;
            if (!dis[r][c][nd][color]) {
              dis[r][c][nd][color] = len + 1;
              q.push((State){r, c, nd, color});
            }
          }
          r += dx[dir];
          c += dy[dir];
          color = (color + 1) % 5;
          if (r >= 0 && r < R && c >= 0 && c < C && grid[r][c] != '#' && !dis[r][c][dir][color]) {
            dis[r][c][dir][color] = len + 1;
            q.push((State){r, c, dir, color});
          }
      }
    }
    if (!found) {
      cout << "destination not reachable"<< endl<< endl;
    }
  }
  return 0;
}