#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 대소문자 구분을 하지 않는다
// transform(str.begin(), str.end(), str.begin(), ::tolower);
// 캐시 교체 알고리즘은 LRU(Least Recently Used)

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    if(cacheSize == 0) return cities.size()*5;

    for(int i=0; i<cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto it = find(cache.begin(), cache.end(),cities[i]);
        //cache miss
        if(it == cache.end()){ 
            answer+=5;
            if(cache.size()==cacheSize){
                cache.erase(cache.begin());
            }
            cache.push_back(cities[i]);
        }
        //cache hit
        //LRU
        else {
            answer+=1;
            cache.erase(it);
            cache.push_back(cities[i]);
        }
    }
    
    return answer;
}
