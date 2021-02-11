#include <iostream>

using namespace std;

int row, col, cnt = 0;
int** map;
int** dp;
int check_down(int x, int y);

int main() {
	cin >> row >> col;

	map = new int* [row];
	dp = new int* [row];
	for (int i = 0; i < row; i++) {
		map[i] = new int[col];
		dp[i] = new int[col];
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
			dp[i][j] = 0;
		}
	}

	check_down(0, 0);

	cout << cnt;

	for (int i = 0; i < row; i++) {
		delete[] map[i];
		delete[] dp[i];
	}
	delete[] map;
	delete[] dp;
	return 0;
}

int check_down(int x, int y) {
	if (dp[x][y] == 0) {
		dp[x][y] = 1;
		if (x == row - 1 && y == col - 1) {
			cnt++;
			return 0;
		}
		if (x - 1 >= 0) { //위쪽 확인
			if (map[x - 1][y] < map[x][y]) {
				check_down(x - 1, y);
			}
		}
		if (y - 1 >= 0) { //왼쪽 확인
			if (map[x][y - 1] < map[x][y]) {
				check_down(x, y - 1);
			}
		}
		if (y + 1 < col) { //오른쪽 확인
			if (map[x][y + 1] < map[x][y]) {
				check_down(x, y + 1);
			}
		}
		if (x + 1 < row) { //아래쪽 확인
			if (map[x + 1][y] < map[x][y]) {
				check_down(x + 1, y);
			}
		}
	}
	else {
		cnt++;
		return 0;
	}
}