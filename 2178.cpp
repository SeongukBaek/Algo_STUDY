#include <iostream>
#include <cstring>

using namespace std;

int row, col, min_cnt = 1000;
char** map;
int** visited;
int x_ar[4] = { -1, 0, 1, 0 };
int y_ar[4] = { 0, 1, 0, -1 };

int maze(int x, int y, int block);

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

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] == '1' && visited[i][j] == -1) {
				cnt = maze(i, j, cnt);
			}
			if (min_cnt > cnt)
				min_cnt = cnt;
		}
	}
	cout << min_cnt;

	for (int i = 0; i < row; i++) {
		delete[] map[i];
		delete[] visited[i];
	}
	delete[] map;
	delete[] visited;
	return 0;
}
// 탐색하다가 더이상 탐색할 수 없는 경우 리턴값 문제 생각
int maze(int x, int y, int block) {
	if (x == row - 1 && y == col - 1)
		return block + 1;
	if (visited[x][y] == -1) {
		block++;
		visited[x][y] = 1;
		
		for (int i = 0; i < 4; i++) {
			int new_x = x + x_ar[i];
			int new_y = y + y_ar[i];

			if (new_x >= 0 && new_x < row && new_y >= 0 && new_y < col)
				if (map[new_x][new_y] == '1')
					block = maze(new_x, new_y, block);
		}
	}
	return block;
}