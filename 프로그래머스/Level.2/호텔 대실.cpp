#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    vector<pair<int, int>> times;
    
    for(int i; i<book_time.size(); i++){
        pair<int, int> p;
        p.first = stoi(book_time[i][0].substr(0, 2)) * 100 + stoi(book_time[i][0].substr(3, 2));
        p.second = stoi(book_time[i][1].substr(0, 2)) * 100 + stoi(book_time[i][1].substr(3, 2)) + 10;
        if(p.second % 100 >= 60){ // 분단위 계산 60(60분) = 100(1시간)
            p.second = p.second - 60 + 100;
        }
        times.push_back(p);
    }

    sort(times.begin(), times.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(times[0].second);
    
    for(int i=1; i<times.size(); i++){
        if(pq.top() > times[i].first){
            answer += 1;
        }
        else{
            pq.pop();
        }
        pq.push(times[i].second);
    }

    return answer;
}
