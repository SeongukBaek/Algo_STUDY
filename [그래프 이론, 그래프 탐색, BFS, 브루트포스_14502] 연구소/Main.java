import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Loc {
    int x, y;

    public Loc(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

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

    public Lab (int N, int M) {
        this.N = N;
        this.M = M;
        map = new int[N][M];
        copyMap = new int[N][M];
        orgSafe = new Loc[N*M];
        locQueue = new LinkedList<>();
    }

    public int findMaxSafeArea() {
        setWall(0,3);
        return safeArea;
    }

    private void setWall(int idx, int count) {
        if (count == 0) {
            spreadVirus();
            int result = countAndReset();
            if (safeArea < result) safeArea = result;
        } else {
            count--;
            for (int i = idx; i < idx0; i++) {
                copyMap[orgSafe[i].x][orgSafe[i].y] = 1;
                setWall(i + 1, count);
                copyMap[orgSafe[i].x][orgSafe[i].y] = 0;
            }
        }
    }

    private void spreadVirus() {
        for (int i = 0; i < locQueue.size(); i++) {
            Loc tmpLoc = locQueue.poll();
            bfs(tmpLoc.x, tmpLoc.y);
            locQueue.add(tmpLoc);
        }
    }

    private void bfs(int x, int y) {
        Queue<Loc> queue = new LinkedList<>();
        queue.add(new Loc(x, y));

        while (!queue.isEmpty()){
            Loc tmp = queue.poll();
            for (int i = 0; i < 4; i++) {
                int nx = tmp.x + rangeX[i], ny = tmp.y + rangeY[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (copyMap[nx][ny] == 0) {
                    queue.add(new Loc(nx, ny));
                    copyMap[nx][ny] = 2;
                }
            }
        }
    }

    private int countAndReset() {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (copyMap[i][j] == 0) count++;
                if (copyMap[i][j] == 2) {
                    if (locQueue.contains(new Loc(i, j))) continue;
                    copyMap[i][j] = map[i][j];
                }
            }
        }
        return count;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int M = Integer.parseInt(line[1]);

        Lab lab = new Lab(N, M);

        for (int i = 0; i < N; i++) {
            lab.map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for (int j = 0; j < M; j++) {
                if (lab.map[i][j] == 2)
                    lab.locQueue.add(new Loc(i, j));
                else if (lab.map[i][j] == 0)
                    lab.orgSafe[lab.idx0++] = new Loc(i, j);
                lab.copyMap[i][j] = lab.map[i][j];
            }
        }

        br.close();

        System.out.println(lab.findMaxSafeArea());
    }
}