#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void dfs(int s);
void bfs(int s);

int n, m, sv;
vector<int> g[1001];
vector<int> path;
int visited[1001] = { 0, };
int main() {
	cin >> n >> m >> sv;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for (int i = 0; i < n; i++) {
		sort(g[i].begin(), g[i].end());
	}

	dfs(sv);
	for (auto i = path.begin(); i != path.end(); i++)
		cout << *i << " ";
	path.clear();
	fill_n(visited, 1001, 0);
	cout << "\n";

	bfs(sv);
	for (auto i = path.begin(); i != path.end(); i++)
		cout << *i << " ";

	return 0;
}

void dfs(int sv) {
	if (visited[sv] == 0) {
		path.push_back(sv);
		visited[sv] = 1;
		for (int i = 0; i < g[sv].size(); i++) {
			if (visited[g[sv][i]] == 0) {
				dfs(g[sv][i]);
			}
		}
	}
}

void bfs(int sv) {
	queue<int> q;
	q.push(sv);
	visited[sv] = 1;
	path.push_back(sv);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < g[cur].size(); i++) {
 			if (visited[g[cur][i]] == 0) {
				visited[g[cur][i]] = 1;
				path.push_back(g[cur][i]);
				q.push(g[cur][i]);
			}
		}
	}
}