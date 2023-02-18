#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    
    int Arow = arr1.size();
    int Acol = arr1[0].size();
    int Bcol = arr2[0].size();
    
    for(int a=0; a<Arow; a++){
        vector<int> v;
        for(int b=0; b<Bcol; b++){
            int num = 0;
            for(int c=0; c<Acol; c++){
                num += arr1[a][c] * arr2[c][b];
            }
            v.push_back(num);
        }
        answer.push_back(v);
    }
    
    return answer;
}
