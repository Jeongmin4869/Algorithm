#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> board) {
    queue<pair<int, int>> q;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int N = board.size(), M = board[0].size();
    int Ex, Ey;
    vector<vector<int>> count;
    count.assign(N, vector<int>(M, 1000));
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j]=='R'){
                q.push({i, j});
                count[i][j] = 0;
            }
            if(board[i][j]=='G'){
                Ex = i;
                Ey = j;
            }
        }
    }
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int xx = x;
            int yy = y;
            while(true){
                xx += dx[i];
                yy += dy[i];
                if(xx>=N || xx<0 || yy>=M || yy<0 || board[xx][yy] == 'D'){
                    xx -= dx[i];
                    yy -= dy[i];
                    if(count[xx][yy]>count[x][y]+1){
                        count[xx][yy] = count[x][y]+1;
                        cout << count[xx][yy] << endl;
                        q.push({xx,yy});
                    }
                    break;
                }
            }
        }
    }
    
    return count[Ex][Ey]>=1000?-1:count[Ex][Ey];
}
