#include <iostream>
using namespace std;

void dfs(int idx);
void isExist(int idx, int friends);

int N, M, get_friends = 0;
pair <int, int> f[2000];
int visited[2000];

int main() {
	cin >> N >> M;

	for (int i = 0; i < M;i++)
		cin >> f[i].first >> f[i].second;

	for (int j = 0; j < N; j++)
		visited[f[j].first] = visited[f[j].second] = -1;

	for (int i = 0; i < M; i++) {
		isExist(i, 1);
		if (get_friends == 1)
			break;
	}
	cout << get_friends;
	return 0;
}

void dfs(int idx, int friends) {
	if (friends == 4)
		get_friends = 1;
	else {
		visited[idx] = 1;
		for (int i = 0; i < M; i++) {
			if (visited[i] == -1 && f[i]) {
				friends++;
				dfs(i, friends);
			}
		}
	}
}

void isExist(int idx, int friends) {
	if (friends == 4) {
		get_friends = 1;
		return;
	}
	else {
		int a = f[idx].first, b = f[idx].second;
		if (visited[a] == -1) {
			visited[a] = 1;
			for (int i = 0; i < M; i++) {
				if (visited[f[i].first] == -1) {
					if (f[i].first == a || f[i].second == a) {
						friends++;
						isExist(i, friends);
					}
				}
			}
			visited[a] = -1;
		}
		if (visited[b] == -1) {
			visited[b] = 1;
			for (int i = 0; i < M; i++) {
				if (visited[f[i].second] == -1) {
					if (f[i].first == b || f[i].second == b) {
						friends++;
						isExist(i, friends);
					}
				}
			}
			visited[b] = -1;
		}
	}
}