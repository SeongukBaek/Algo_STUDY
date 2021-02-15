#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int row, col, min_cnt = 1000;
char** map;
int** visited;
int x_ar[4] = { -1, 0, 1, 0 };
int y_ar[4] = { 0, 1, 0, -1 };

int maze(pair<int, int> input);

int main() {
	int cnt = 0;
	cin >> row >> col;

	map = new char* [row];
	visited = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new char[col];
		visited[i] = new int[col];
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			visited[i][j] = -1;
		}
	}

	maze(make_pair(0, 0));

	for (int i = 0; i < row; i++) {
		delete[] map[i];
		delete[] visited[i];
	}
	delete[] map;
	delete[] visited;
	return 0;
}

int maze(pair<int, int> input) {
	if (input.first == row - 1 && input.second == col - 1)
		return 0;
	else {
		queue<pair<int, int>> q;
		pair<int, int> cur = input;
		int block = 1;
		q.push(input);
		visited[cur.first][cur.second] = 1;
		while (!q.empty()) {
			cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++) {
				pair<int, int> next = make_pair(input.first + x_ar[i], input.second + y_ar[i]);

				if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col) {
					if (map[next.first][next.second] == '1' && visited[next.first][next.second] != 1) {
						visited[next.first][next.second] = 1;
						block++;
						if (next.first == row - 1 && next.second == col - 1)
							return block;
						q.push(make_pair(next.first, next.second));
					}
				}
			}
			maze(cur);
		}
	}
}