#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minrow = 50, maxrow = 0;
    int mincell = 50, maxcell = 0;
    
    for(int i=0; i<wallpaper.size(); i++){
        for(int j=0; j<wallpaper[i].size(); j++){
            if(wallpaper[i][j] == '#'){
                if(minrow > i) minrow = i;
                if(maxrow < i) maxrow = i;
                if(mincell > j) mincell = j;
                if(maxcell < j) maxcell = j;
            }
        }
    }
    
    answer.push_back(minrow);
    answer.push_back(mincell);
    answer.push_back(maxrow+1);
    answer.push_back(maxcell+1);
    
    return answer;
}
