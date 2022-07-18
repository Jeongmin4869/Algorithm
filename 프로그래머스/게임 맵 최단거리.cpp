#include<vector>
#include<string.h> // memset
using namespace std;

bool visited[100][100];
int dx[4];
int dy[4];
int N, M, count=0;
vector<vector <int>> map;

void dfs(int y, int x){
    
    map[y][x] = 1;
    count++;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny >= 0 && nx >= 0 && ny < N && nx < M){
            if(!map[ny][nx]){ // 0 이라면 ...
                dfs(ny, nx);
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    
    //memset(visited, false, sizeof(visited));
    map = maps;
    
    dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
    dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
    
    int answer = 0;
    
    N = maps.size();
    M = maps[0].size();
    
    // 캐릭터는 게임 맵의 좌측 상단인 (1, 1) 
    // 상대방 진영은 게임 맵의 우측 하단인 (n, m) 위치
    
    dfs(0,0);
    
    
    return answer;
    
}
