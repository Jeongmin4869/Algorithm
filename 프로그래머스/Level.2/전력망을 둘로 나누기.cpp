#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*

n     : 송전탑의 개수
wires : 전선 정보 

*/

int g[101][101] = {0}; // 그래프
vector<bool> visited;  // 방문여부

int dfs(int index, int n){
    
    if(visited[index])  // 방문했을 경우 count 세지 않는다
        return 0;
    
    visited[index] = true;
    int count = 1;
    for(int i=1; i<=n; i++){
        if(g[index][i]){  // 그래프가 이어져있는 경우
            count += dfs(i, n);
        }
    }
    
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for(int i=0; i<wires.size(); i++){
        int x = wires[i][0];
        int y = wires[i][1];
        g[x][y] = g[y][x] = 1;
    }
    
    for(int i=0; i<wires.size(); i++){
        int x = wires[i][0];
        int y = wires[i][1];
        g[x][y] = g[y][x] = 0;
    
        visited.assign(n+1, false);
        vector<int> part;
        
        for(int j=1; j<=n; j++){
            int val = dfs(j, n);
            if(val == 0) continue;
            part.push_back(val);
        }
        
        answer = min(answer, abs(part[0] - part[1]));
        if(answer == 0) break;
        g[x][y] = g[y][x] = 1;
    }    

    return answer;
}
