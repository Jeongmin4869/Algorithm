#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {

    int Hindex = 0;
    int h1, h2;
    sort(citations.begin(), citations.end());
    for(int i = 0; i<citations.size(); i++){
        h1 = citations.size() - i;
        h2 = citations[i];
        int minn = min(h1,h2);
        if(minn < Hindex) break;
        Hindex = minn;
    }
    return Hindex;
}
