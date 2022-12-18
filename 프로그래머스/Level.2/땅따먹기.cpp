#include <algorithm>
#include <vector>
using namespace std;

// DP : 동적계산법
// 한번씩 내려가면서 최고의 합을 기억하며 내려오기

int solution(vector<vector<int> > land)
{
    int size = land.size();
    for(int i=1; i<size; i++){
        for(int j=0; j<land[i].size(); j++){
            int val = land[i][j];
            for(int k = 0; k<land[i].size(); k++){
                if(k!=j && val < land[i-1][k] + land[i][j])
                    val = land[i-1][k] + land[i][j];
            }
            land[i][j] = val;
        }
    }
   
    return *max_element(land[size-1].begin(), land[size-1].end());
}
