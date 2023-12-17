#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool visited[100][100];
int dx[4];
int dy[4];
int M, N;
int sum = 0;

void dfs(int x, int y, vector<string> maps){
    visited[x][y] = true;
    sum += maps[x][y] - '0';
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M) continue;
        if(!visited[nx][ny] && maps[nx][ny] != 'X'){
            dfs(nx, ny, maps);
        }
    }
    return ;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    memset(visited, false, sizeof(visited));
    dx[0] = 1, dx[1] = 0, dx[2] = -1, dx[3] = 0;
    dy[0] = 0, dy[1] = 1, dy[2] = 0, dy[3] = -1;
    
    M = maps.size();
    N = maps[0].size();
    
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(maps[i][j]!='X' && !visited[i][j]){
                sum = 0;
                dfs(i, j, maps);
                answer.push_back(sum);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.size() == 0) answer.push_back(-1);
    
    return answer;
}
