#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> al = {"A", "E", "I", "O", "U"};
int count = 0;
int answer;

void dfs(string s, string word){

    if(s == word){
        answer = count;
        return;
    }
    
    if(s.size() == 5){ // ???
        return;
    }
    
    for(int i=0; i<al.size(); i++){
        count++;
        string str = s + al[i];
        dfs(str, word);
        
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}
