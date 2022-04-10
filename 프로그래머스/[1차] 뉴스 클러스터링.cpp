#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> v(string str) {
	char before = tolower(str[0]);
	vector<string> vec;
	for (int i = 1; i < str.size(); i++) {
		if (tolower(str[i]) < 'a' || tolower(str[i]) > 'z') continue;
		string s;
		s.append(1, before);
		s.append(1, tolower(str[i]));
		vec.push_back(s);
		before = tolower(str[i]);
	}
	return vec;

}

int solution(string str1, string str2) {
	float answer = 0;
	int inter, uni; // 교, 합집합

	vector<string> vec1, vec2;
	vec1 = v(str1);
	vec2 = v(str2);
	uni += vec1.size() + vec2.size();

	for (int i = 0; i < vec1.size(); i++) {
		if (find(vec2.begin(), vec2.end(), vec1[i]) != vec2.end()) {
			inter++;
			vec1.erase(vec1.begin() + i--);
		}
	}
	uni -= inter;
	answer = (float)inter / uni;
	//cout << answer;

	return (int)(answer * 65536) / 1;
}