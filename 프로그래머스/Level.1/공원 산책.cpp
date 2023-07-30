#include <string>
#include <vector>

using namespace std;

//answer[y][x];

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer = {0,0};
    int y=0, x=0;
    
    for(int i=0; i<park.size(); i++){
        for(int j=0; j<park[i].size(); j++){
            if(park[i][j] == 'S'){
                answer[0] = y = i;
                answer[1] = x = j;
            }
        }
    }
    
    for(int i=0; i<routes.size(); i++){
        
        y = answer[0];
        x = answer[1];
        
        switch(routes[i][0]){
            case 'N':
                y -= routes[i][2] - '0';
                break;
            case 'S':
                y += routes[i][2] - '0';
                break;
            case 'W':
                x -= routes[i][2] - '0';
                break;
            case 'E':
                x += routes[i][2] - '0';
                break;
        }
        
        
        if(x >= 0 && x < park[0].size() && y >= 0 && y < park.size()){
            
            bool flag = true;
            int preX = answer[1];
            int nowX = x;
            for(int i= min(preX,nowX); i<= max(preX,nowX); i++){
                if(park[answer[0]][i] == 'X'){
                    flag = false;
                    break;
                }
            }
            
            int preY = answer[0];
            int nowY = y;
            for(int i= min(preY, nowY); i<=max(preY, nowY); i++){
                if(park[i][answer[1]] == 'X'){
                    flag = false;
                    break;
                }
            }
            
            if(flag == true){
                answer[0] = y;
                answer[1] = x;
            }
        }
        
    }
    
    return answer;
}
