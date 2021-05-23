#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, K, cost = 0;
vector <int> parents, generator;
vector <pair<int, int>> graph[100001];

int findParent(int a) {
	if (a == parents[a])
		return a;
	return parents[a] = findParent(parents[a]);
}

bool unionParent(int u, int v) {
	u = findParent(u);
	v = findParent(v);
	if(u == v)
		return ;
	if(generator[u])
		parents[v] = u;
	else if(generator[v])
		parents[u] = v;
	else
		parents[v] = u;
}

void prim(int s) {
	visited[s] = 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < graph[s].size(); i++) {
		pq.push(make_pair(graph[s][i].second, graph[s][i].first));
	}
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		cost += curCost;
		if (visited[cur] == 1) break;
		visited[cur] = 1;

		for (int i = 0; i < graph[cur].size(); i++)
			pq.push(make_pair(graph[cur][i].second, graph[cur][i].first));
			
	}
}

int main() {
	cin >> N >> M >> K;
	visited.resize(N + 1);
	for (int i = 0; i < K; i++) {
		int s;
		cin >> s;
		visited[s] = 1;
	}

	for (int i = 1; i < M + 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	for (int i = 1; i < N + 1; i++) {
		if (visited[i] != 1)
			prim(i);
	}
	cout << cost;
	return 0;
}