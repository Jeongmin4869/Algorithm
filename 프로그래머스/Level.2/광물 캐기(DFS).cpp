#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>


using namespace std;

// 2. DFS 백트래킹

// picks는 [dia, iron, stone]과 같은 구조
// 광물은 주어진 순서대로만 캘 수 있습니다.
// 각 곡괭이는 종류에 상관없이 광물 5개를 캔 ../후에는 더 이상 사용할 수 없습니다.
// 최소한의 피로도로 광물을 캐려고 합니다.

int energy[3][3] = {{1,1,1},{5,1,1},{25,5,1}};
map<string, int> m;
int mine_size;
int answer;

void dfs(vector<int> &picks, vector<string> &minerals, int now, int sum){
    
    int sumarr[3] = {0, };
    
    // 백트래킹
    if(sum > answer) return;
    
    // 종료조건
    if(now >= mine_size || (picks[0] == 0 && picks[1] == 0 && picks[2] == 0)){
        answer = min(answer, sum);
        return;
    }
    
    int nnow = now;
    
    for(int i=0; i<5; i++){
        nnow = now + i;
        if(nnow >= mine_size){
            break;
        }
        sumarr[0] += energy[0][m[minerals[nnow]]];
        sumarr[1] += energy[1][m[minerals[nnow]]];
        sumarr[2] += energy[2][m[minerals[nnow]]];
        
    }
    
    for(int i=0; i<3; i++){
        if(picks[i] != 0){
            picks[i] -= 1;
            dfs(picks, minerals, nnow+1, sum + sumarr[i]);
            picks[i] += 1;
        }
    }
    
}

int solution(vector<int> picks, vector<string> minerals) {
    m.insert({"diamond", 0});
    m.insert({"iron", 1});
    m.insert({"stone", 2});
    mine_size = minerals.size();
    answer = mine_size * 25;
    
    dfs(picks, minerals, 0, 0);

    return answer;
}
