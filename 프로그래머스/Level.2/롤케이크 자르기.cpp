#include <string>
#include <vector>
#include <set>
#include <map>

// set만 사용하면 런타임 에러 난다. 
// set은 내부적으로 R-B Tree로 구현되어 있어 연산에 logn의 시간이 걸린다. 

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int person1 = 0, person2 = 0;
    map<int,int> m;
    set<int> s;
    
    for(int i=0 ;i<topping.size(); i++){
        m[topping[i]] += 1;
    }
    
    person2 = m.size();
    
    for(int i=0; i<topping.size(); i++){
        s.insert(topping[i]);
        person1 = s.size();
        m[topping[i]] -= 1;
        if(m[topping[i]] == 0) person2 -= 1;
        if(person1 == person2) answer += 1;
        if(person1 > person2) break;
    }
    
    return answer;
}
