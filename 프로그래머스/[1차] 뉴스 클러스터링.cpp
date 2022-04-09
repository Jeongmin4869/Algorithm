#include <string>
#include <vector>

using namespace std;

vector<string> v(string str) {
	char before = tolower(str[0]);
	vector<string> vec;
	for (int i = 1; i < str.size(); i++) {
		if (tolower(str[i]) < 'a' || tolower(str[i]) > 'z') continue;
		string s = to_string(before) + to_string(tolower(str[i]));
		vec.push_back(s);
		before = str[i];
	}
	return vec;

}

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> vec1, vec2;
	vec1 = v(str1);
	vec2 = v(str2);
	for (int i = 0; i < vec1.size(); i++) {
		//if(find(vec2.begin(), vec2.end(), vec1[i]) !)
	}


	return answer;
}