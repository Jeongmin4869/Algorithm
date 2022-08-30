#include <string>
#include <vector>
#include <map>

using namespace std;

// (x+a)(x+b)(x+c) = x3 + (a+b+c)x2 + (ab+bc+ca)x + (abc)

int solution(vector<vector<string>> clothes) {
    map<string , int> map;
    int answer = 0;
    for(vector v : clothes){
        map[v[1]]++;
    }
    
    int n = 1;
    for(auto m : map){
        n *= (m.second+1);
    }
     answer += n -1;
    
    return answer;
}
