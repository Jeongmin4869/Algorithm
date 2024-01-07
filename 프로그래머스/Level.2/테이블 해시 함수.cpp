#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int column;

bool cmp(vector<int> a, vector<int> b){
    if(a[column] == b[column]) return b[0] < a[0];
    return a[column] < b[column];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col-1;
    sort(data.begin(), data.end(), cmp);
    
    /*
    sort(data.begin(),data.end(),[col](auto a,auto b){
        return (a[col]!=b[col]) ? (a[col]<b[col]) : (a[0]>b[0]);
    });
    */
    
    for(int i=row_begin-1 ;i<row_end; i++){
        int mod = 0;
        for(int j=0; j<data[i].size(); j++){
            mod += data[i][j]%(i+1);
        }
        answer = answer ^ mod;
    }
    return answer;
}
