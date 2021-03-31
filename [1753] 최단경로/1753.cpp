#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int sp(int goal);
int v, e, s;
int graph[20001][20001];
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
	cin >> v >> e >> s;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}

	for (int i = 0; i < v; i++) {
		int path = sp(i + 1);
		if (path == -1)
			cout << "INF" << "\n";
		else
			cout << path << "\n";
	}

	return 0;
}

int sp(int goal) {
	int p = -1;
	if (s == goal)
		p = 0;
	else {
		for (int i = 0; i < v; i++) {
			for (int j = 0; j < v; j++) {

			}
		}
	}
	return p;
}