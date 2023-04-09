#include <string>
#include <vector>
using namespace std;

/*
솔루션1. 벡터를 문자열로 만들어, 문자열에서 find 하여 "1234" 가 있을경우 erase => 탐색하는 시간 오래걸림
솔루션2. vector의 back(), pop_back() 사용 => stack은 top()을 수정할 수 없어, v의 back()을 사용
*/

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v = {0};
    for(int i : ingredient){
        if(v.back() == 1 && i == 2) v.back() = 12;
        else if(v.back() == 12 && i == 3) v.back() = 123;
        else if(v.back() == 123 && i == 1) answer++, v.pop_back();
        else v.push_back(i);
    }
    return answer;
}
