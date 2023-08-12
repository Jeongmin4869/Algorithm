#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer = {0,0};
    
    while(s != "1"){
        
        answer[0] += 1;
        int count = 0;
        
        for(int i=0; i<s.length(); i++){           
            if(s[i] == '0') count += 1;
        }
        
        int num = s.length() - count;
        s = "";
        
        while(num > 0){
            s = to_string(num%2) + s;
            num/=2;
        }
        
        answer[1] += count;

    }    
    return answer;
}
