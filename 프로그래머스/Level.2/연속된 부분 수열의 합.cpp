#include <string>
#include <vector>
using namespace std;

/*

투포인터 알고리즘
1. 시작점과 끝점이 첫번째 원소의 인덱스를 가리키도록 한다.
2. 현재 부분 합이 M과 같다면 카운트한다.
3. 현재 부분 합이 M보다 작다면 end를 1 증가시킨다.
4. 현재 부분 합이 M보다 크거나 같다면 start를 1 증가시킨다.
5. 모든 경우를 확인할 때까지 2-4번 과정을 반복한다.

*/

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0,0};
    int min_count = sequence.size()+1;
    int N = sequence.size();
    int count = 1;
    int sum = sequence[0];
    int s = 0, e = 0;
    
    while(e <= N){
        if(sum == k){
            if(count < min_count){
                answer[0] = s;
                answer[1] = e;
                min_count = count;
            }
        }
        
        if(sum <= k){
            e++;
            if(e<N){
                sum += sequence[e];
                count += 1;
            }
        }
        else if(sum > k){
            sum -= sequence[s];
            count -= 1;
            s += 1;
        }
    }
    
    return answer;
}
