#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> map;
    for(int i=0; i<tangerine.size(); i++){
        map[tangerine[i]] += 1;
    }
    
    vector<int> v;
    for(auto m : map){
        v.push_back(m.second);
    }
    
    sort(v.begin(), v.end(), greater<>());
    int nowk = 0;
    for(int i=0; i<v.size(); i++){
        answer+=1;
        nowk += v[i];
        if(nowk >= k) break;
    }
    
    return answer;
}
