#include <string>
#include <vector>
#include <stack>
using namespace std;

// 보조 컨테이너 벨트를 이용해도 기사님이 원하는 순서대로 상자를 싣지 못 한다면, 더 이상 상자를 싣지 않습니다.
// 일단 보조컨테이너 벨트에 넣고 확인한다. 
// 보조컨테이너벨트는 스택구조이다. 
int solution(vector<int> order) {
    int answer = 0;
    int index = 0;
    stack<int> s;
    
    for(int count = 1; count <= order.size(); count ++){
        s.push(count);
        while(!s.empty() && index<order.size()){
            if(order[index] == s.top()){
                answer += 1;
                index+=1;
                s.pop();
            }
            else 
                break;
        }
    }

    return answer;
}
