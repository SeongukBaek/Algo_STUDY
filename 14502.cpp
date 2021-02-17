#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int row, col, idx = 0, boundary_cnt = 3;
int** map;
int x_ar[4] = { -1, 0, 1, 0 };
int y_ar[4] = { 0, 1, 0, -1 };
pair <int, int> two[64];

void set_boundary(int x, int y);
void spreadout(int x, int y);
int safezone();

int main() {
	cin >> row >> col;

	map = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				two[idx].first = i, two[idx++].second = j;
		}
	}
	for (int i = 0; i < idx; i++)
		set_boundary(two[i].first, two[i].second);

	for (int i = 0; i < idx; i++)
		spreadout(two[i].first, two[i].second);

	cout << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}

	cout << safezone();

	for (int i = 0; i < row; i++) {
		delete[] map[i];
	}
	delete[] map;
	return 0;
}

void setboundary(int x, int y) {
	queue <pair<int, int> > q;
	pair<int, int> cur = make_pair(x, y);
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(cur.first + x_ar[i], cur.second + y_ar[i]);

			if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col) {
				if (map[next.first][next.second] == 0) {
					q.push(make_pair(next.first, next.second));
				}
			}
		}
	}
}

void spreadout(int x, int y) {
	queue <pair<int, int> > q;
	pair<int, int> cur = make_pair(x, y);
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(cur.first + x_ar[i], cur.second + y_ar[i]);

			if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col) {
				if (map[next.first][next.second] == 0) {
					q.push(make_pair(next.first, next.second));
					map[next.first][next.second] = 2;
				}
			}
		}
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