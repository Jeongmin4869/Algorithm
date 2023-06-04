#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> lank;
    for(int i=0; i<score.size(); i++){
        lank.push_back(score[i]);
        sort(lank.begin(), lank.end());
        if(i >= k) {
            lank.erase(lank.begin());
        }
        answer.push_back(lank[0]);
    }
    
    return answer;
}
