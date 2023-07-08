#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    bool flag;
    int sum;
    
    for(int i=0; i<targets.size(); i++){
        sum = 0;
        flag = true;
        for(int j=0; j<targets[i].size(); j++){
            int min = 101; // 키보드는 1부터 100까지이다. 101일 경우 목표문자열을 찾지 못한 경우다. 
            for(int k=0; k<keymap.size(); k++){
                auto p = find(keymap[k].begin(), keymap[k].end(), targets[i][j]);
                if(p != keymap[k].end()){ // 목표 문자열이 있을경우
                    int val = p-keymap[k].begin()+1;
                    if(min > val) min = val; // 목표 문자열을 가질 수 있는 최솟값을 구한다. 
                }     
            }
            if(min == 101){ // 목표 문자를 찾지 못한 경우
                flag = false; // flag로 문자를 찾지 못했음을 저장한다.
                break;
            }
            sum += min;
        }
        if(!flag) answer.push_back(-1); // 목표 문자 찾지 못할 경우 -1을 저장한다. 
        else answer.push_back(sum);
    }
    return answer;
}
