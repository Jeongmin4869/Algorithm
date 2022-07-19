#include<vector>
#include<string.h> // memset
using namespace std;

bool visited[100][100];
int dx[4];
int dy[4];
int N, M, min_count = 10000;
bool enable = false;
vector<vector <int>> map;

/*********************************
dfs로 구현 버전
테스트 케이스는 전부 통과하였으나
효율성을 통과하지 못함
*********************************/

void dfs(int y, int x, int count){
    count++;
    if(y == N-1 && x == M-1){
        if(count < min_count) min_count = count;
        enable = true;
        return;
    }
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny >= 0 && nx >= 0 && ny < N && nx < M){
            if(map[ny][nx]){ // 1(길)이라면..
                map[y][x] = 0;
                dfs(ny, nx, count);
            }
        }
    }
    map[y][x] = 1;
    
}

int solution(vector<vector<int> > maps)
{
    
    map = maps;
    min_count = 10000;
    enable = false;
    
    dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
    dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
    
    int answer = 0;
    
    N = maps.size();
    M = maps[0].size();
    
    // 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 
    // 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치
    
    dfs(0,0,0);
    
    if(enable) answer = min_count;
    else return -1;
    
    return answer;
    
}
