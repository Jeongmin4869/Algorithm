#include<vector>
#include<iostream>
#include<queue>
using namespace std;

int dx[4];
int dy[4];
int N, M, min_count = 10000;
vector<vector <int>> map;
queue<pair<int,int>> q;

//dfs -> bfs((너비우선 탐색)
//dfs(깊이우선탐색)은 모든 노드를 탐색할때
//bfs(너비우선탐색)은 최단 거리를 탐색할때
//bfs는 자료구조 Queue사용

void bfs(int y, int x, int count){

    while(!q.empty()){
        count ++ ;
        
    }
    
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
    
    q.push(pair(0,0));

    if(enable) answer = min_count;
    else return -1;
    return answer;
    
}
