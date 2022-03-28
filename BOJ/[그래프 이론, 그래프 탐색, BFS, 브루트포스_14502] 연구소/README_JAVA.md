# [14502] 연구소 - Java

## :pushpin: **Algorithm**

그래프 이론, 그래프 탐색, BFS, 브루트포스

## :round_pushpin: **Logic**

```java
class Lab {
    Queue<Loc> locQueue;
    int N, M;
    int safeArea = 0;
    int[][] map;
    int[][] copyMap;
    int[] rangeX = { -1, 0, 1, 0 };
    int[] rangeY = { 0, 1, 0, -1 };

    Loc[] orgSafe;
    int idx0 = 0;
    ...
        
}
```

- 연구소의 정보를 관리하는 클래스
- 원본 연구소 정보를 저장하는 `map` 과 바이러스를 실제로 퍼뜨릴 `copyMap` 을 사용한다.
- 또한 벽을 세울 공간들을 저장하는 `orgSafe` 배열을 사용한다.
- `setWall()` 재귀 호출로 벽을 세우고, 벽을 다 세운 다음, `spreadVirus()` 에서 BFS 방식으로 바이러스를 퍼뜨린다.
- 이후, `countAndReset()` 으로 바이러스가 퍼진 이후의 안전 영역을 카운트하고, `map` 을 이용해 `copyMap` 을 바이러스가 퍼지기 전 상태로 돌려놓는다.

## :black_nib: **Review**
- 원래의 연구소 정보를 간직하기 위해 `map` 과 `copyMap` 배열을 두고 진행했는데, 계속 두 배열이 동기화된 것마냥 값이 같이 변경되고 있었다. 아무래도 `lab.map[i] = lab.copyMap[i];` 이 코드 때문에 인스턴스의 주소 공유나 참조의 문제일거라 생각해 검색해보니 아니나 다를까 "얕은 복사와 깊은 복사" 문제였다. 한 번 정리해야겠다.
- 바이러스가 퍼진 이후 다시 원상복구할때, 세운 벽까지 없애버리는 초기화 과정떄문에 값이 계속 잘못 나왔다. 초기화 과정은 항상 잘 확인하자.