#include <iostream>

using namespace std;

int N, weak_cnt = 0, normal_cnt = 0, redgreen = 0, blue = 0;
char** picture;
int** visited;
int x_ar[4] = { -1, 0, 0, 1 };
int y_ar[4] = { 0, -1, 1, 0 };

void color_cnt(int x, int y);

int main() {
	cin >> N;

	picture = new char* [N];
	visited = new int* [N];
	for (int i = 0; i < N; i++) {
		picture[i] = new char[N];
		visited[i] = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> picture[i][j];
			visited[i][j] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j] == -1) {
				color_cnt(i, j);
				if (picture[i][j] == 'R' || picture[i][j] == 'G')
					weak_cnt++;
				normal_cnt++;
			}
		}
	}

	cout << "ÀüÃ¼: " << normal_cnt << endl << "red+green" << redgreen << endl << "blue" << blue << endl << "weak_cnt" << weak_cnt;
	for (int i = 0; i < N; i++) {
		delete[] picture[i];
		delete[] visited[i];
	}
	delete[] picture;
	delete[] visited;
	return 0;
}

void color_cnt(int x, int y) {
	if (visited[x][y] == -1) {
		char color = picture[x][y];
		visited[x][y] = 1;

		for (int i = 0; i < 4; i++) {
			int new_x = x + x_ar[i], new_y = y + y_ar[i];

			if (new_x >= 0 && new_x < N && new_y >= 0 && new_y < N) {
				if (visited[new_x][new_y] == -1) {
					if (color == 'B')
						blue++;
					else
						redgreen++;
					color_cnt(new_x, new_y);
				}
			}
		}
	}
}