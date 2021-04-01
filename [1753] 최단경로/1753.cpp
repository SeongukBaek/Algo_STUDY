#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

void sp();
int short_dist(int goal);

int v, e, s;
vector <pair <int, int>>graph[20001];
int* cost;

int main() {
	cin >> v >> e >> s;

	cost = new int[v + 1];
	fill_n(cost, v + 1, 11);
	cost[s] = 0;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
	}

	sp();

	for (int i = 1; i < v + 1; i++) {
		if (cost[i] == 11)
			cout << "INF" << "\n";
		else
			cout << cost[i] << "\n";
	}

	return 0;
}

void sp() {
	for (int i = 1; i < v + 1; i++) {
		if (s == i)
			cost[i] = 0;
		else {
			cost[i] = short_dist(i);
		}
	}
}

int short_dist(int goal) {
	int w = cost[goal];

	queue <int> q;
	for (int k = 1; k < v + 1; k++) {
		q.push(k);
		for (int i = k; i < v + 1; i++) {
			if (w > graph[s][k] + graph[k][goal])
				w = graph[s][k] + graph[k][goal];
		}
		
	}
		
	
	return w;
}