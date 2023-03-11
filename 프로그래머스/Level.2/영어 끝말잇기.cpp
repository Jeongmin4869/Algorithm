#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};
    map<string, int> map;
    string word = words[0];
    map[word]++;
    int index;
    for(index=1; index<words.size(); index++){
        if(word[word.size()-1] == words[index][0]){
            word = words[index];
            map[word]++;
            if(map[word] > 1){
                break;
            }
        }
        else break;
    }
    if(index!=words.size()){
        answer[0] = index%n+1;
        answer[1] = index/n+1;
    }
    return answer;
}
