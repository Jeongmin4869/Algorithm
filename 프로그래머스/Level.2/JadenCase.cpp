#include <string>
#include <vector>
#include <cctype> // isspace

using namespace std;

string solution(string s) {
    string answer = s;
    answer[0] = toupper(answer[0]);
    
    for(int i=1; i<answer.size(); i++){
        if(isspace(answer[i-1])){
            answer[i] = toupper(answer[i]);
        }
        else {
            answer[i] = tolower(answer[i]);
        }
    }
    
    
    return answer;
}
