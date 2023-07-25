#include <string>
#include <vector>
using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int num = stoi(bin1, nullptr, 2) + stoi(bin2, nullptr, 2);
    if(num == 0) return "0";
    while(num > 0){
        answer = to_string(num%2) + answer;
        num /= 2;
    } 
    return answer;
}
