#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 고려하지 못했던 조건 : 카드를 사용하지 않고 다음 카드로 넘어갈 수 없습니다.

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0, idx2 = 0;
    for(int i=0; i<goal.size(); i++){        
        if(idx1 < cards1.size() && cards1[idx1] == goal[i]){
            idx1++;
            continue;
        }
        if(idx2 < cards2.size() && cards2[idx2] == goal[i]){
            idx2++;
            continue;
        }
        return "No";
    }
    return "Yes";
}
