#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	//1단계
	for (int i : new_id) {
		new_id[i] = tolower(new_id[i]);
	}

	//2단계

	//3단계
	if (new_id[0] == '.') new_id.erase(0);
	if (new_id[new_id.end() - 1] == '.') new_id.erase(new_id.end() - 1);


	return new_id;
}