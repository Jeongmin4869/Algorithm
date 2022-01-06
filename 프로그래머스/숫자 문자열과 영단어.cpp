#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(string s) {
	int answer = 0;
	unordered_map<string, int> hash;
	hash["one"] = 1;
	hash["two"] = 2;
	hash["three"] = 3;
	hash["four"] = 4;
	hash["five"] = 5;
	hash["six"] = 6;
	hash["seven"] = 7;
	hash["eight"] = 8;
	hash["nine"] = 9;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') // 숫자일때

			answer += s[i] % '0';
		//if(hash[substr(i,3)])
	}

	return answer;
}