#include <string>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

int solution(string s) {
	int answer = 0;
	unordered_map<int, string> hash;
	hash[1] = "one";
	hash[2] = "two";
	hash[3] = "three";
	hash[4] = "four";
	hash[5] = "five";
	hash[6] = "six";
	hash[7] = "seven";
	hash[8] = "eight";
	hash[9] = "nine";

	for (int i = 1; i < 10; i++) {
		/*
		if(s[i] >= '0' && s[i] <= '9') // 숫자일때
			answer += s[i]%'0';
		*/
		if (strchr(s, hash[i]))
			printf("a");
		//strchr("-_.", ch)
	}

	//string에 '0' 곱해서 답하기
	return answer;
}