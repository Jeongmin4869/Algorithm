#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// 0과 1로 이루어짐.
//[[0,0,0,0]] : 0 , [[0,0,1,0]] : 1
// DP 다이나믹 프로그래밍(또는 동적 계획법)
int solution(vector<vector<int>> board)
{
    int max = 0;
    int space[1001][1001] = {0};
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            space[i+1][j+1] = board[i][j];
        }
    }
    
    for(int i=1; i<board.size()+1; i++){
        for(int j=1; j<board[0].size()+1; j++){
            if(board[i-1][j-1] == 1 )
                space[i][j] = min(space[i][j-1], min(space[i-1][j], space[i-1][j-1])) + 1;
            
            if(space[i][j] > max) max = space[i][j];
        }
    }
    
    return pow(max,2);
}
