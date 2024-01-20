#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 1. 한 번에 하나의 원판만 옮길 수 있습니다.
// 2. 큰 원판이 작은 원판 위에 있어서는 안됩니다.
// 1번에는 n개의 원판이 있고 이 n개의 원판을 3번 원판으로 최소 횟수로 옮기려고 합니다.
// 하노이의탑 -> 재귀함수  

/*
start에 위치한 N-1개의 원판을 (start, target에 속하지 않는) temp로 옮기고
start에 위치한 가장 큰 원판을 target으로 옮기고
temp에 위치한 N-1개의 원판을 target으로 옮겨야 합니다.

크기가 N-1인 원반을 보조 점으로 먼저 옮기는 것이다. 
*/
vector<vector<int>> answer;
void hanoi(int start, int target, int temp, int n ){
    if(n==0) return;
    // 모두 temp로 옮긴 후 
    hanoi(start, temp, target, n-1);
    // 여기서 아지막 남은 것을 start -> target
    cout << start << " , " << target << endl;
    answer.push_back({start, target});
    // temp에 있던 것을 target 으로 
    hanoi(temp, target, start, n-1);
    
}

vector<vector<int>> solution(int n) {
    hanoi(1, 3, 2, n);
    return answer;
}
