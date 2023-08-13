#include <vector>
#include <queue>
#include <iostream>
using namespace std;


/*
마을의 개수 N
각 마을을 연결하는 도로의 정보 road
음식 배달이 가능한 시간 K
1번 마을에 있는 음식점이 K 이하의 시간에 배달이 가능한 마을의 개수를 리턴
>> 다익스트라 알고리즘

c++의 우선순위 큐는 Max Heap설정되어있다.
여기서는 우선순위 큐를 Min Heap으로 사용하였다. 
*/

vector<pair<int, int>> v[51]; // 마을들의 양방향 간선 벡터 저장
vector<int> dist; // 각 마을마다 최단거리 기록

void dijkstra(){
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq; // Min Heap
    pq.push({1,0}); // 초기값. 1부터 시작한다. 
    
    while(!pq.empty()){
        int cur = pq.top().first; // 현재위치
        int cost = pq.top().second; // 이동거리
        pq.pop();
        
        for(int i=0; i<v[cur].size(); i++){ // 현재 cur와 연결된 모든 노드들과의 거리를 비교한다. 
            int next = v[cur][i].first; // 다음 큐의 노드 위치
            int ncost = v[cur][i].second; // 다음 큐의 노드 이동거리
            if(dist[next] > dist[cur] + ncost){ // 최소 이동거리 갱신
                dist[next] = dist[cur] + ncost;
                pq.push({next, ncost});
            }
        }
 
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist.resize(N+1, 2e9); // 처음에 무한대로 초기화. 2e9 = 2000000000
    
    for(int i=0; i<road.size(); i++){
        int s = road[i][0];
        int e = road[i][1];
        int cost = road[i][2];
        
        v[s].push_back({e, cost});
        v[e].push_back({s, cost});
    }
    
    dist[1] = 0; // 1에서 1까지 거리 0
    dijkstra();
    
    for(int i=1; i<dist.size(); i++){
        if(dist[i] <= K) answer += 1;
    }
    
    return answer;
}
