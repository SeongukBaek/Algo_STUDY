#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt = 0;
int* nums;
int* visited;
int* ans;

int dfs(int start, int idx);

int main() {
	cin >> N;

	nums = new int[N + 1];
	visited = new int[N + 1];
	nums[0] = visited[0] = -1;
	ans = new int[N];
	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		if (i == nums[i]) {
			visited[i] = 1;
			ans[cnt++] = i;
		}
		else {
			visited[i] = -1;
			ans[i - 1] = 0;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i] == -1)
			dfs(i, i);
	}

	sort(ans, ans + cnt);

	cout << cnt << endl;
	for (int i = 0; i < cnt; i++)
		cout << ans[i];

	delete[] nums, visited, ans;
	return 0;
}

int dfs(int start, int idx) {
	int check = 0;
	if (visited[idx] == -1) {
		visited[idx] = 1;
		check = dfs(start, nums[idx]);
		if (check == 1)
			ans[cnt++] = start;
		start = idx;
	}
	else {
		if (start == idx)
			return 1;
	}
	return 0;
}