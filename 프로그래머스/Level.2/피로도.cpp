#include <string>
#include <vector>
using namespace std;

int s;
int answer = 0;
vector<bool> visited;

void dfs(int len, int count, int HP, vector<vector<int>> dungeons){
    if(answer < count) answer = count;
    
    for(int i=0; i<s; i++){
        if(!visited[i]){
            visited[i] = true;
            if(HP < dungeons[i][0])
                dfs(len+1, count , HP-dungeons[i][1],dungeons);
            else
                dfs(len+1, count+1, HP-dungeons[i][1],dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    s = dungeons.size();
    visited.assign(8,false);
    dfs(0,0,k,dungeons);

    return answer;
}
