#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 통로들 중 한 칸에는 미로를 빠져나가는 문이 있는데, 이 문은 레버를 당겨서만 열 수 있습니다. 
// 아직 레버를 당기지 않았더라도 출구가 있는 칸을 지나갈 수 있습니다.
// 최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 합니다.
// 탈출할 수 없다면 -1을 return 해주세요.

int bfs(int x, int y, int ex, int ey, vector<string> &map ){
    int N = map.size(), M = map[0].size();
    int visited[101][101] = {0,}; // 0 // 초기화 하지 않을 경우 에러 발생. 왜??
    int count[101][101] = {0,};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> q;

    q.push(make_pair(x, y));
    visited[x][y] = 1; // 방문했을 경우 0 -> 1
    while(!q.empty()){
        int x2 = q.front().first;
        int y2 = q.front().second;
        q.pop();    
        
        for(int i=0; i<4; i++){
            int nx = x2 + dx[i];
            int ny = y2 + dy[i];
            if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
            if(!visited[nx][ny] && map[nx][ny] != 'X'){
                visited[nx][ny] = 1; 
                count[nx][ny] = count[x2][y2] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return count[ex][ey]>0?count[ex][ey]:-1;
}

int solution(vector<string> maps) {
    int Sx, Sy; // 시작지점
    int Ex, Ey; // 출구
    int Lx, Ly; // 레버
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            if(maps[i][j] == 'S'){
                Sx = i;
                Sy = j;
            }
            
            if(maps[i][j] == 'E'){
                Ex = i;
                Ey = j;
            }
            
            if(maps[i][j] == 'L'){
                Lx = i;
                Ly = j;
            }
        }
    }
    
    int len1 = bfs(Sx, Sy, Lx, Ly, maps);
    int len2 = bfs(Lx, Ly, Ex, Ey, maps);
    if(len1<0 || len2 < 0) return -1;
    return len1 + len2;
}
