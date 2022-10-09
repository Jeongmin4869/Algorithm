#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int count = -1; // 시간
    int noww = 0; // 현재 다리 위에있는 트럭들의 무게
    queue<pair<int,int>> q;
    
    for(int i=0 ;i<truck_weights.size();){
        
        count++;
        
        while(noww + truck_weights[i] <= weight){
            q.push(pair(truck_weights[i],count));
            noww+=truck_weights[i++];
            count++;
        }
        
        while(q.front().second + weight < count){
            count++;
        }
        
        if(q.front().second + weight == count){
            noww-=q.front().first;
            q.pop();
        }
       
    }
    
    return count;
}
