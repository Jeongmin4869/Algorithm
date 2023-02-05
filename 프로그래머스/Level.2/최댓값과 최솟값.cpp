#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<long long> v;
    
    stringstream stream;
    stream.str(s);
    string sign;
    while(stream >> sign){
        v.push_back(stoi(sign));
    }
    
    sort(v.begin(), v.end());
    answer += to_string(v[0]) + " " + to_string(v[v.size()-1]);
    
    return answer;
}
