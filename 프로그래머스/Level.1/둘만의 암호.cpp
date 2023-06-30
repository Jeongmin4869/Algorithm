#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string solution(string s, string skip, int index) {
    string answer = s;    
    for(int i=0; i<s.length(); i++){
        for(int j=1; j<=index; j++){
            answer[i] += 1;
            if(answer[i] > 'z') answer[i] = 'a';
            if(find(skip.begin(), skip.end(), answer[i]) != skip.end()) j--;
        }
    }
    return answer;
}
