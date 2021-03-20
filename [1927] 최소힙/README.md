# [1927] 최소 힙 - C ++

## :pushpin: **Algorithm**

자료구조, 우선순위 큐

## :round_pushpin: **Logic**

```c++
priority_queue <int, vector<int>, greater<int>> cards;
```

- 오름차순으로 `int`형 값들을 저장하는 우선순위 큐 선언

```c++
for (int i = 0; i < N; i++) {
    cin >> n;
    if (n == 0) {
        if (cards.size() == 0)
            cout << 0 << "\n";
        else {
            cout << cards.top() << "\n";
            cards.pop();
        }
    }
    else
        cards.push(n);
}
```

- 입력값이 `0`인 경우와 아닌 경우로 구분
  - 가장 최소인 원소가 맨 앞에 위치

## :black_nib: **Review**

- 우선순위 큐를 오름차순으로 선언