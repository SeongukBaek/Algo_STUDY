# [2437] 저울 - C ++

## :pushpin: **Algorithm**

그리디 알고리즘, 정렬

## :round_pushpin: **Logic**

```c++
for (int i = 0; i < N; i++) {
    string s = words[i];
    int p = 1;
    for (int j = s.size() - 1; j >= 0; j--) {
        w[s[j] - 65] += p;
        p *= 10;
    }
}
sort(w, w + 26, cmp);

for (int i = 0; i < 26; i++) {
    if (w[i] == 0)
        break;
    max_sum += (w[i] * num--);
}
```

- 문자열에 존재하는 문자를 숫자형식으로 변환시킴
  - **ex.  ABC --> C: 1, B: 10, A: 100**
- 내림차순 정렬된 `w`배열을 읽으면서 `9`부터 차례로 변환된 숫자에 곱하여 더함

## :black_nib: **Review**

- 수를 1부터 늘려가며 주어진 추로 잴 수 있는지를 확인하는 코드 작성 -> 시간초과
- 