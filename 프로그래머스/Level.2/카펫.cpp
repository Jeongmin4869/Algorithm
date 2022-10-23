#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> b;

    for(int i=1; i<=sqrt(yellow); i++){
        if(yellow%i == 0) b.push_back(i);
    }
    
    for(int i=0; i<b.size(); i++){
        int h = yellow/b[i];
        int w = b[i];
        if((h*2) + (w*2) + 4 == brown){
            answer.push_back(h+2);
            answer.push_back(w+2);
            break;
        }
    }
    
    return answer;
}
