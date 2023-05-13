#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    vector<string> words = {"aya", "ye", "woo", "ma"};
    for(int i = 0; i<babbling.size(); i++){
        string str = babbling[i];
        int back_index = -1;
        for(int w_index = 0; w_index < words.size(); w_index++){
            string word = words[w_index];            
            if(word == str.substr(0, word.size())){
                if(w_index == back_index) continue;
                str = str.substr(word.size());
                back_index = w_index;
                w_index = -1;
            }
        }
        if(str.size() == 0){
            answer ++;
        }
    }
    
    
    return answer;
}
