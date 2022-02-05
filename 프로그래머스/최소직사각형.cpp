#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int w = 0, h = 0;
	for (int i = 0; i < sizes.size(); i++) {
		h = max(h, max(sizes[i][0], sizes[i][1]));
		w = max(w, min(sizes[i][0], sizes[i][1]));
	}
	return w * h;
}