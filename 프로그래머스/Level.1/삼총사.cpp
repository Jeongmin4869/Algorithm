#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool visited[13];


void dfs(int index, int cnt, int sum, vector<int> number){
    
    if(cnt == 3) {
        if(sum == 0){
            answer += 1;
        }
        return;
    }
    
    for(int i=index; i<number.size(); i++){
        if(!visited[i]){
            visited[i] = true;
            int n = sum + number[i];
            dfs(i, cnt+1, n, number);
            visited[i] = false;
        }
    }
    
    
}

int solution(vector<int> number) {

    dfs(0, 0, 0, number);
    
    return answer;
}
