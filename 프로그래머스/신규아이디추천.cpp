#include <string>
#include <vector>


using namespace std;

string solution(string new_id) {
	string answer = "";

	//1�ܰ�
	for (int i = 0; i < new_id.length(); i++) {
		new_id[i] = tolower(new_id[i]);
	}


	//2�ܰ�

	for (int i = 0; i < new_id.length(); i++) {
		if ((new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') ||
			(new_id[i] >= 'a' && new_id[i] <= 'z') ||
			(new_id[i] >= '1' && new_id[i] <= '9')) {//����
			printf("d", new_id.c_str());
			continue;
		}
		else {
		}

	}



	//3�ܰ�
	for (int i = 0; i < new_id.length() - 1; i++) {
		if (new_id[i] == new_id[i + 1] && new_id[i] == '.') {
			new_id.erase(i + 1);
			i--;
		}
	}
	//printf("%s", new_id.c_str());

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