#include <string>
#include <vector>


using namespace std;

string solution(string new_id) {
	string answer = "";

	//1�ܰ�
	for (int i : new_id) {
		new_id[i] = tolower(new_id[i]);
	}

	//2�ܰ�

	//3�ܰ�

	//4�ܰ�
	if (new_id[0] == '.') new_id.erase(0);
	if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.length() - 1);

	//5�ܰ�
	if (new_id.length() == 0) new_id = "a";

	//6�ܰ�
	if (new_id.length() >= 16) new_id = new_id.substr(0, 15);
	if (new_id[new_id.length() - 1] == '.') new_id.erase(new_id.length() - 1);

	//7�ܰ�
	if (new_id.length() <= 2) {
		string last = new_id.substr(new_id.length(), new_id.length());
		while (new_id.length() == 3) {
			new_id.append(last);
		}
	}

	return new_id;
}