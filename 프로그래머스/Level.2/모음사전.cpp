#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> al = {"A", "E", "I", "O", "U"};
int count = 0;
int answer;

void dfs(string s, string word, int depth){
    
    cout << s << endl;
    
    if(depth >= 5){ // ???
        return;
    }
    
    if(s == word){
        cout << s.size() << " , " << s <<  endl;
        answer = count;
        return;
    }
    
    for(int i=0; i<al.size(); i++){
        if(depth < 5){ // ???
            count++;
            s = s + al[i];
            dfs(s, word, depth+1);
        }
    }
}

int solution(string word) {
    dfs("", word, 0);
    return answer;
}
