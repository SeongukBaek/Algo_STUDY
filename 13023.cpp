#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isExist(int idx);

bool comp(pair <int, int> a, pair <int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int N, M, friends = 1;
vector<pair <int, int>> f;
int* visited;

int main() {
	cin >> N >> M;
	int m = M;

	visited = new int[M];
	while (m--) {
		int a, b;
		cin >> a >> b;
		f.push_back(make_pair(a, b));
		visited[m] = -1;
	}
	sort(f.begin(), f.end(), comp);

	for (int i = 0; i < M; i++) {
		if (isExist(i) == 1) {
			cout << "1";
			return 0;
		}
		friends = 1;
	}
	cout << "0";
	return 0;
}

int isExist(int idx) {
	if (friends == M)
		return 1;
	else {
		for (int i = idx + 1; i < M; i++) {
			if (f[i].first == f[idx].first || f[i].second == f[idx].first || f[i].first == f[idx].second || f[i].second == f[idx].second) {
				friends++;
				return isExist(i);
			}
		}
	}
}