#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string str1 = "";
    string str2;
    for(int i=1; i<food.size(); i++){
        for(int j=0; j<food[i]/2; j++){
            str1 += to_string(i);
        }
    }
    str2 = str1;
    sort(str2.begin(), str2.end(), greater<>());
    answer += str1 + "0" + str2;
    return answer;
}
