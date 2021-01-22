#include <iostream>
using namespace std;

int check_paper(int x, int y, int N);

int N = 0;
int zero = 0, one = 0, m_one = 0; // 종이 개수 count
int** arr;

int main() {
    cin >> N;

    arr = new int* [N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[N];
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];
    }
    
    check_paper(0, 0, N);

    cout << m_one << endl << zero << endl << one;

    for (int i = 0; i < N; i++)
        delete[] arr[i];
    delete[] arr;

    return 0;
}

int check_paper(int x, int y, int a) {
    int cnt0 = 0, cnt1 = 0, cntm1 = 0;
    if (a > 1) {
        for (int i = x; i < x + a; i++) {
            for (int j = y; j < y + a; j++) {
                if (arr[i][j] == 0)
                    cnt0++;
                else if (arr[i][j] == -1)
                    cntm1++;
                else
                    cnt1++;
            }
        }
        if (cnt0 == a * a) {
            zero++;
        }
        else if (cntm1 == a * a) {
            m_one++;
        }
        else if (cnt1 == a * a) {
            one++;
        }
        else {
            for (int i = x; i < x + a; i += a / 3) {
                for (int j = y; j < y + a; j += a / 3) {
                    check_paper(i, j, a / 3);
                }
            }
        }
    }
    else if (a == 1) {
        if (arr[x][y] == 0)
            zero++;
        else if (arr[x][y] == -1)
            m_one++;
        else
            one++;
    }
    return 0;
} 