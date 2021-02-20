#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int row, col, idx = 0, boundary_cnt = 3, max_area = 0;
int** map;
int** copy_map;
int** visited;
int x_ar[4] = { -1, 0, 1, 0 };
int y_ar[4] = { 0, 1, 0, -1 };
pair <int, int> two[64];

void set_boundary(int x, int y);
void spreadout();
int safezone();

int main() {
	cin >> row >> col;
	int max_area = 0, zero = 0;

	map = new int* [row];
	copy_map = new int* [row];
	visited = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		copy_map[i] = new int[col];
		visited[i] = new int[col];
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
			visited[i][j] = -1;
			if (map[i][j] == 2)
				two[idx].first = i, two[idx++].second = j;
		}
	}

	//for (int i = 0; i < idx; i++)
	//	set_boundary(two[i].first, two[i].second);
		
	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << copy_map[i][j] << " ";
		cout << endl;
	}

	cout << max_area;

	for (int i = 0; i < row; i++) {
		delete[] map[i];
		delete[] visited[i];
	}
	delete[] map;
	delete[] visited;
	return 0;
}
// 완전 탐색으로 벽 세우기
void set_boundary(int x, int y) {
	if (boundary_cnt == 0) {
		spreadout();
		boundary_cnt = 3;
	}
	else {
		boundary_cnt--;
		//set_boundary();
	}
}

void spreadout() {
	for (int i = 0; i < idx; i++) {
		queue <pair<int, int> > q;
		pair<int, int> cur = make_pair(two[i].first, two[i].second);
		q.push(cur);
		while (!q.empty()) {
			cur = q.front();
			q.pop();
			for (int a = 0; a < 4; a++) {
				pair<int, int> next = make_pair(cur.first + x_ar[a], cur.second + y_ar[a]);

				if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col) {
					if (map[next.first][next.second] == 0) {
						q.push(make_pair(next.first, next.second));
						map[next.first][next.second] = 2;
					}
				}
			}
		}
		int area = safezone();
		if (max_area < area)
			max_area = area;
	}
}

int safezone() {
	int cnt = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			if (map[i][j] == 0)
				cnt++;
	}
	return cnt;
}