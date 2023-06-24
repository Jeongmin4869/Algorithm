#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_len = p.length(), t_len = t.length();
    for(int i = 0; i<=(t_len - p_len); i++){
        string str = t.substr(i, p_len);
        if(str <= p) 
            answer++;
    }

    return answer;
}
