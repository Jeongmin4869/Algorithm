#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer = players;
    map<string, int> names;
    
    /*
    
    // index를 구하는 부분에서 효율성 통과를 하지 못한다. 
    // map 자료구조를 이용하도록 한다. 
    
    vector<string> answer = players;
    for(int i=0; i<callings.size(); i++){
        int index = find(answer.begin(), answer.end(), callings[i]) - answer.begin(); 
        string temp;
        temp = answer[index-1];
        answer[index-1] = answer[index];
        answer[index] = temp;
    }
    */
    
    for(int i=0; i<answer.size(); i++){
        names[answer[i]] = i;
    }
    
    for(int i=0; i<callings.size(); i++){
        int lank = names[callings[i]];
        names[callings[i]] = lank - 1;
        names[answer[lank-1]] = lank;
      
        string temp = answer[lank-1];
        answer[lank-1] = answer[lank];
        answer[lank] = temp;
        
    }
    return answer;
}
