#include<vector>
#include<queue>
using namespace std;

int dx[4];
int dy[4];
int N, M;
queue<pair<int,int>> q;
vector<vector<int>> count;
vector<vector<int>> map;
//dfs -> bfs((너비우선 탐색)
//dfs(깊이우선탐색)은 모든 노드를 탐색할때
//bfs(너비우선탐색)은 최단 거리를 탐색할때
//bfs는 자료구조 Queue사용

int solution(vector<vector<int> > maps)
{
    map = maps;
    int answer = 0;
    N = maps.size();
    M = maps[0].size();
    count.assign(N,vector <int>(M,0));
    
    dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
    dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;

    //bfs
    q.push(pair(0,0));
    count[0][0] = 1;
    pair<int, int>  po;
    while(!q.empty()){
        po = q.front();
        map[po.first][po.second] = 0; // 이미 지나온 길 0
        q.pop();
        for(int i=0; i<4; i++){
            int ny = po.first + dy[i];
            int nx = po.second + dx[i];
            if(ny >= 0 && nx >= 0 && ny < N && nx < M){
                if(map[ny][nx] == 1){
                    map[ny][nx] = 0;
                    count[ny][nx] = count[po.first][po.second] + 1;
                    q.push(pair(ny,nx));
                }
            }
        }
    }
    
    
    if(count[N-1][M-1]!=0) answer = count[N-1][M-1];
    else return -1;
    return answer;
    
}
