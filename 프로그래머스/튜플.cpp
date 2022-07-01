#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int> map;
    int n;
    
    // '{', ',' '}' 다 공백으로 replace
    for(int i=0; i<s.size(); i++){
        if(s[i] == '{' || s[i] == '}' || s[i] == ',')
            s[i] = ' ';
    }
    
    //숫자 추출
    stringstream ss;
    ss.str(s);
    while(ss >> n){
        map[n]++;
    }
    
    //벡터를 사용해 map을 value값으로 정렬 ( 튜풀 )
    vector<ii> v(map.begin(), map.end());
    sort(v.begin(), v.end(), [](ii a, ii b){
        return a.second > b.second;
    });
    
    for(ii a : v){
        answer.push_back(a.first);
    }
    
    return answer;
}
