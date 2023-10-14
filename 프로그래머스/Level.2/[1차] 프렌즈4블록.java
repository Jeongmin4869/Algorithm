#include <string>
#include <vector>
#include <algorithm> // swap()
#include <iostream>

using namespace std;

// 블록의 첫 배치가 주어졌을 때, 지워지는 블록은 모두 몇 개인지 판단하는 프로그램을 제작하라.

int solution(int m, int n, vector<string> board) {
    int answer = 0, count = 0;
    vector<vector<pair<char, bool>>> v(m); // 블럭과 블럭의 존재유무 
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            v[i].push_back({board[i][j], true});
        }
    }
    
    while(true){
        // 1. 4개의 블럭 체크
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(v[i][j].first   == v[i+1][j].first and
                   v[i][j].first   == v[i][j+1].first and 
                   v[i+1][j].first == v[i+1][j+1].first){
                    v[i][j].second     = false;
                    v[i+1][j].second   = false;
                    v[i][j+1].second   = false;
                    v[i+1][j+1].second = false;
                    
                }
            }
        }
        
        count = 0;
        // 2. 블럭 삭제
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!v[i][j].second and v[i][j].first != ' '){
                    v[i][j].first = ' ';
                    count += 1;
                }
            }
        }
        if(count == 0) break;
        answer += count;

        // 3. 맵 업데이트
        for(int i=m-1; i>0; i--){
            for(int j=0; j<n; j++){
                if(v[i][j].first == ' ' and !v[i][j].second){
                    int row = i;
                    while(row>0){
                        row--;
                        if(v[row][j].second) break;
                    }
                    swap(v[i][j], v[row][j]);
                } 
            }
        }
        cout << endl;
    }
    
    
    return answer;
}
