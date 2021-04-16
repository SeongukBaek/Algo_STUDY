# [1260] DFS, BFS - C++

## :pushpin: **Algorithm**

그래프 이론, 그래프 탐색, DFS, BFS

## :round_pushpin: **Logic**

```c++
vector<int> g[1001];

for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
}
```

- 그래프의 정보를 저장하기 위해 `vector` 자료형을 이용함

```c++
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
```

- DFS 구현

```c++
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
```

- BFS 구현

## :black_nib: **Review**

- `DFS`와 `BFS` 알고리즘을 구현하는 것에는 문제가 없었지만 자꾸 `path`가 말썽이어서 쓸데없이 시간 허비했음.
- 시험공부하다가 너무 하기 싫어서 그냥 잠깐 끄적함 ..
