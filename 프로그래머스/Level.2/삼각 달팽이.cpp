#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int arr[n][n];
    int row = n;
    int x = 0, y = 0;
    int count = 1;
    while(row > 0){
        for(int i=0; i<row; i++){
            arr[y+i][x] = count++;
        }
        for(int i=1; i<row; i++){
            arr[y+row-1][x+i] = count++;
        }
        for(int i=1; i<row-1; i++){
            arr[y+row-1-i][x+row-1-i] = count++;
        }
        row -= 3;
        y += 2;
        x += 1;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            answer.push_back(arr[i][j]);
        }
    }
    
    
    return answer;
}
