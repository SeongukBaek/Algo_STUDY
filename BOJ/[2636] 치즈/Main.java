import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
	private static int ROW;
	private static int COL;
	private static int[][] board;
	private static int cheeses;
	private static Deque<int[]> meltCheese;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		ROW = Integer.parseInt(st.nextToken());
		COL = Integer.parseInt(st.nextToken());
		board = new int[ROW][COL];

		for (int x = 0; x < ROW; x++) {
			st = new StringTokenizer(br.readLine());
			for (int y = 0; y < COL; y++) {
				int number = Integer.parseInt(st.nextToken());
				board[x][y] = number;
				if (number == 1) {
					cheeses++;
				}
			}
		}

		// �� Ž�� -> ������ ġ�� ���
		// ġ�� ���ֱ�, ���� ġ�� �� ���
		int hour = 0;
		int prev = cheeses;

		while (cheeses != 0) {
			hour++;
			searchEdge();
			// ���� ġ�� ���� ����
			int meltCheeseCount = meltCheese.size();
			prev = cheeses;
			cheeses -= meltCheeseCount;
			melt();
		}

		System.out.println(hour);
		System.out.println(prev);
	}

	private static int[][] directions = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

	private static void searchEdge() {
		meltCheese = new ArrayDeque<>();
		Deque<int[]> locations = new ArrayDeque<>();
		boolean[][] isVisited = new boolean[ROW][COL];
		locations.add(new int[] {0,0});
		isVisited[0][0] = true;
		
		while (!locations.isEmpty()) {
			int[] current = locations.poll();
			
			for (int[] direction : directions) {
				int nx = current[0] + direction[0];
				int ny = current[1] + direction[1];
				
				if (!isIn(nx, ny) || isVisited[nx][ny]) {
					continue;
				}

				isVisited[nx][ny] = true;
				int[] next = {nx, ny};
				
				if (board[nx][ny] == 1) {
					meltCheese.add(next);
					continue;
				}
				
				locations.add(next);
			}
		}
	}

	private static boolean isIn(int x, int y) {
		return x >= 0 && x < ROW && y >= 0 && y < COL;
	}

	private static void melt() {
		while (!meltCheese.isEmpty()) {
			int[] cheese = meltCheese.poll();
			board[cheese[0]][cheese[1]] = 0;
		}
	}
}