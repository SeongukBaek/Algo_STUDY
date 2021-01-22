#include <iostream>
#include <cstring>
using namespace std;

void quadtree(int x_idx, int y_idx, int n);

int N;
char** arr;
char one = '1';

int main() {
    cin >> N;

    arr = new char* [N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[N];
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }

    quadtree(0, 0, N);

    for (int i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

void quadtree(int x, int y, int n) {
    int cnt0 = 0, cnt1 = 0;
    if (n > 1) {
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (arr[i][j] == one)
                    cnt1++;
                else
                    cnt0++;
            }
        }
        if (cnt1 == n * n) cout << "1";
        else if (cnt0 == n * n) cout << "0";
        else {
            cout << "(";
            for (int i = x; i < x + n; i += n / 2) {
                for (int j = y; j < y + n; j += n / 2) {
                    quadtree(i, j, n / 2);
                }
            }
            cout << ")";
        }
    }
    else if (n == 1) {
        cout << arr[x][y];
    }
}