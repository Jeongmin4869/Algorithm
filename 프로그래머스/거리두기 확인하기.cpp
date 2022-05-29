#include <string>
#include <vector>
#include <string.h> // memset
#include <iostream>
using namespace std;
bool visited[5][5];

int dx[4];
int dy[4];
<<<<<<< Updated upstream
bool isSafe ;
void dfs(int y, int x, vector<string> place, int count){
    visited[y][x] = true;
    if(count>2 || place[y][x] == 'X') {
        return;
    }
    else {
        if(count !=0 && place[y][x] == 'P') {
            isSafe =false; 
            return;
        }
    
        for(int i=0; i<4; i++){
            int px = x+dx[i];
            int py = y+dy[i];
            if((px>=0&&py>=0) && (px<5 && py<5)){
                if(!visited[py][px]){
                    visited[py][px] = true;
                    dfs(py,px,place,count+1);
                    visited[py][px] = false; // 없애면 오류남
                }
            }
        }
    }
    //return;
=======
bool isSafe;
void dfs(int y, int x, vector<string> place, int count) {
	visited[y][x] = true;
	if (count > 2 || place[y][x] == 'X') {
		return;
	}
	else {
		if (count != 0 && place[y][x] == 'P') {
			isSafe = false;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int px = x + dx[i];
			int py = y + dy[i];
			if ((px >= 0 && py >= 0) && (px < 5 && py < 5)) {
				if (!visited[py][px]) {
					visited[py][px] = true;
					dfs(py, px, place, count + 1);
					visited[py][px] = false; // 없애면 오류남
				}
			}
		}
	}
	//return;
>>>>>>> Stashed changes
}

//P좌표로 풀기? 탐색으로 풀기?
vector<int> solution(vector<vector<string>> places) {
<<<<<<< Updated upstream
    vector<int> answer;
    dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
    dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
    for(vector<string> place : places){
        isSafe = true;
        memset(visited, false, sizeof(visited));
        for(int y=0; y<5; y++){
            for(int x=0; x<5; x++){
               if(place[y][x] == 'P'){
                    cout<<'P';
                    dfs(y, x, place, 0);
                    if(!isSafe) break;
                } 
            }
            if(!isSafe) break;
        }
        isSafe==true?answer.push_back(1) : answer.push_back(0);
    }
    return answer;
}
=======
	vector<int> answer;
	dx[0] = 1; dx[1] = 0; dx[2] = -1; dx[3] = 0;
	dy[0] = 0; dy[1] = 1; dy[2] = 0; dy[3] = -1;
	for (vector<string> place : places) {
		isSafe = true;
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				if (place[y][x] == 'P') {
					cout << 'P';
					dfs(y, x, place, 0);
					if (!isSafe) break;
				}
			}
			if (!isSafe) break;
		}
		isSafe == true ? answer.push_back(1) : answer.push_back(0);
	}
	return answer;
}
>>>>>>> Stashed changes
