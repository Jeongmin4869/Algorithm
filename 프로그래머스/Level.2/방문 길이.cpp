#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 방향성 추가해야한다 
int solution(string dirs) {
    int answer = 0;
    vector<string> visited;
    visited.assign(121, "0000");
    int nowx = 5, nowy = 5;
    
    for(int i=0; i<dirs.size(); i++){
        
        int ax = nowx, ay = nowy;     
        int index = 0;
        if(dirs[i] == 'U') {ay -= 1, index = 1, visited[nowy*11 + nowx][0] = '1';}
        else if(dirs[i] == 'D') {ay += 1, index = 0, visited[nowy*11 + nowx][1] = '1';}
        else if(dirs[i] == 'R') {ax += 1, index = 3, visited[nowy*11 + nowx][2] = '1';}
        else if(dirs[i] == 'L') {ax -= 1, index = 2, visited[nowy*11 + nowx][3] = '1';}
        
        if(ay < 0 || ay > 10 || ax < 0 || ax >10) continue;
        
        if(visited[ay*11+ax][index] != '1'){
            answer += 1;
        }
        
        visited[ay*11+ax][index] = '1';
        nowx = ax;
        nowy = ay;
        
    }
    
    return answer;
}
