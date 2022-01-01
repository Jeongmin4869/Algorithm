#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	int i;
	unordered_map<string, int> hash;

	for (i = 0; i < participant.size(); i++) {
		if (hash.count(participant.at(i)) == 0)
			hash.insert(make_pair(participant.at(i), 1));
		else {
			hash[participant.at(i)] = hash[participant.at(i)] + 1;
		}
	}

	for (i = 0; i < completion.size(); i++) {
		hash[completion.at(i)] = hash[completion.at(i)] - 1;
	}

	for (i = 0; i < participant.size(); i++) {

		if (hash[participant.at(i)] > 0)
			return participant.at(i);
	}

	return " ";
}