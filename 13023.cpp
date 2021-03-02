#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int isExist(int idx, int friends);

bool comp(pair <int, int> a, pair <int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int N, M;
vector<pair <int, int>> f;
int visited[2000];

int main() {
	cin >> N >> M;
	int m = M;

	while (m--) {
		int a, b;
		cin >> a >> b;
		f.push_back(make_pair(a, b));
	}
	sort(f.begin(), f.end(), comp);

	for (int i = 0; i < M; i++) {
		int friends = 2;
		for (int j = 0; j < N; j++)
			visited[j] = -1;

		if (isExist(i, friends) == 1) {
			cout << "1";
			return 0;
		}
	}
	cout << "0";
	return 0;
}

int isExist(int idx, int friends) {
	if (friends == 5)
		return 1;
	else {
		int a = f[idx].first, b = f[idx].second, check = friends;
		if (visited[a] == -1) {
			visited[a] = 1;
			for (int i = 0; i < M; i++) {
				if (i != idx) {
					if (f[i].first == a || f[i].second == a) {
						friends++;
						return isExist(i, friends);
					}
				}
			}
			if (check == friends)
				friends--;
		}
		if (visited[b] == -1) {
			visited[b] = 1;
			for (int i = 0; i < M; i++) {
				if (i != idx) {
					if (f[i].first == b || f[i].second == b) {
						friends++;
						return isExist(i, friends);
					}
				}
			}
			if (check == friends)
				friends--;
		}
	}
}