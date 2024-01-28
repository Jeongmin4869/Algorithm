#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 보유한 병사 n명으로 연속되는 적의 공격을 순서대로 막는 게임
// 매 라운드마다 enemy[i]마리의 적이 등장합니다.
// 병사 중 enemy[i]명 만큼 소모하여 enemy[i]마리의 적을 막을 수 있습니다.
// 무적권을 사용하면 병사의 소모없이 한 라운드의 공격을 막을 수 있습니다. 무적권은 최대 k번 사용할 수 있습니다.

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int i = 0;
    for(i=0 ;i<enemy.size(); i++){
        if(k>0){
            pq.push(enemy[i]);
            k -= 1;
            continue;
        }
        
        if(pq.top() < enemy[i]){
            n -= pq.top();
            pq.pop();
            pq.push(enemy[i]);
        }
        else {
            n -= enemy[i];
        }
        
        if(n<0) return i;
        
    }
    
    return i;
}
