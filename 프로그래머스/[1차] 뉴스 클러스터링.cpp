#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> v(string str) {
	char before = tolower(str[0]);
	vector<string> vec;
	for (int i = 1; i < str.size(); i++) {
		if ((before < 'a' || before > 'z')
			|| (tolower(str[i]) < 'a' || tolower(str[i]) > 'z')) {
			before = tolower(str[i]);
			continue;
		}
		string s;
		s.append(1, before).append(1, tolower(str[i]));
		vec.push_back(s);
		before = tolower(str[i]);
	}
	return vec;

}

int solution(string str1, string str2) {
	float answer = 0;
	int inter = 0, uni = 0; // 교, 합집합

	vector<string> vec1, vec2;
	vec1 = v(str1);
	vec2 = v(str2);
	uni += vec1.size() + vec2.size();
	if (uni == 0) return 65536;

	for (int i = 0; i < vec1.size(); i++) {
		if (find(vec2.begin(), vec2.end(), vec1[i]) != vec2.end()) {
			inter++;
			vec2.erase(find(vec2.begin(), vec2.end(), vec1[i]));
			vec1.erase(vec1.begin() + i--);
		}
	}
	cout << endl;
	uni -= inter;
	answer = (float)inter / uni;

	return answer * 65536 / 1;
}