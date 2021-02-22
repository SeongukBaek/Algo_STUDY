#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

<<<<<<< HEAD
int row, col, idx = 0, boundary_cnt = 3, max_area = 0;
int** map;
int** copy_map;
int** visited;
=======
int row, col, idx0 = 0, idx2 = 0, max_area = 0;
int** map;
int** copy_map;
>>>>>>> 5c61be6f589971a697649f95153086cf08085ca0
int x_ar[4] = { -1, 0, 1, 0 };
int y_ar[4] = { 0, 1, 0, -1 };
pair <int, int> two[64];
pair <int, int> zero[64]; 

<<<<<<< HEAD
void set_boundary(int x, int y);
void spreadout();
int safezone();
=======
void set_boundary(int idx, int wall);
void spreadout();
void map_set();
>>>>>>> 5c61be6f589971a697649f95153086cf08085ca0

int main() {
	cin >> row >> col;
	int max_area = 0, zero = 0;

	map = new int* [row];
	copy_map = new int* [row];
<<<<<<< HEAD
	visited = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		copy_map[i] = new int[col];
		visited[i] = new int[col];
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
			visited[i][j] = -1;
=======
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		copy_map[i] = new int[col];
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			copy_map[i][j] = map[i][j];
>>>>>>> 5c61be6f589971a697649f95153086cf08085ca0
			if (map[i][j] == 2)
				two[idx2].first = i, two[idx2++].second = j;
			else if (map[i][j] == 0)
				zero[idx0].first = i, zero[idx0++].second = j;
		}
	}
<<<<<<< HEAD

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
=======
	set_boundary(0, 3);
>>>>>>> 5c61be6f589971a697649f95153086cf08085ca0

	cout << max_area;
	for (int i = 0; i < row; i++) {
		delete[] map[i];
<<<<<<< HEAD
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
=======
		delete[] copy_map[i];
	}
	delete[] map;
	delete[] copy_map;
	return 0;
}

void set_boundary(int idx, int wall) {
	if (wall == 0) {
		spreadout();
		map_set();
	}
	else {
		wall--;
		for (int i = idx; i < idx0; i++) {
			copy_map[zero[i].first][zero[i].second] = 1;
			set_boundary(i + 1, wall);
			copy_map[zero[i].first][zero[i].second] = 0;
		}
>>>>>>> 5c61be6f589971a697649f95153086cf08085ca0
	}
}

void spreadout() {
<<<<<<< HEAD
	for (int i = 0; i < idx; i++) {
=======
	for (int i = 0; i < idx2; i++) {
>>>>>>> 5c61be6f589971a697649f95153086cf08085ca0
		queue <pair<int, int> > q;
		pair<int, int> cur = make_pair(two[i].first, two[i].second);
		q.push(cur);
		while (!q.empty()) {
			cur = q.front();
			q.pop();
<<<<<<< HEAD
			for (int a = 0; a < 4; a++) {
				pair<int, int> next = make_pair(cur.first + x_ar[a], cur.second + y_ar[a]);

				if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col) {
					if (map[next.first][next.second] == 0) {
						q.push(make_pair(next.first, next.second));
						map[next.first][next.second] = 2;
=======
			for (int j = 0; j < 4; j++) {
				pair<int, int> next = make_pair(cur.first + x_ar[j], cur.second + y_ar[j]);

				if (next.first >= 0 && next.first < row && next.second >= 0 && next.second < col) {
					if (copy_map[next.first][next.second] == 0) {
						q.push(make_pair(next.first, next.second));
						copy_map[next.first][next.second] = 2;
>>>>>>> 5c61be6f589971a697649f95153086cf08085ca0
					}
				}
			}
		}
		int area = safezone();
		if (max_area < area)
			max_area = area;
	}
}

void map_set() {
	int check = 0, area = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (copy_map[i][j] == 0)
				area++;
			else if (copy_map[i][j] == 2) {
				for (int a = 0; a < idx2; a++) {
					if (i == two[a].first && j == two[a].second)
						check++;
				}
				if (check == 0)
					copy_map[i][j] = 0;
				check = 0;
			}
		}
	}
	if (max_area < area)
		max_area = area;
}