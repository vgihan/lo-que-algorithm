import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static int dx[] = {-1, 0, 0, 1};
	private static int dy[] = {0, -1, 1, 0};
	private static int field[][];
	private static int n;
	private static Position init;
	private static int sharkSize = 2;
	private static int time = 0;
	private static int exp = 2;
	public static void main(String[] args) throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		field = new int[n][n];
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++) {
				field[i][j] = Integer.parseInt(st.nextToken());
				if(field[i][j] == 9) {
					init = new Position(i, j);
				}
			}
		}
		field[init.x][init.y] = 0;
		solution();
		bw.write(String.valueOf(time));
		
		bw.flush();
		bw.close();
	}
	public static void solution() {
		Position index = bfs(init);
		while(index.x != -1) {
			index = bfs(index);
		}
	}
	public static Position bfs(Position start) {
		Queue<Position> queue = new LinkedList<>();
		boolean check[][] = new boolean[n][n];
		int distance[][] = new int[n][n];
		queue.offer(start);
		check[start.x][start.y] = true;
		while(!queue.isEmpty()) {
			Position index = queue.poll();
			for(int i=0; i<4; i++) {
				int x = index.x + dx[i];
				int y = index.y + dy[i];
				if(!(x >= 0 && y >=0 &&
						 x < n && y < n)) continue;
				if(check[x][y]) continue;
				check[x][y] = true;
				if(field[x][y] > sharkSize) continue;
				queue.offer(new Position(x, y));
				if(field[x][y] == sharkSize || field[x][y] == 0) {
					distance[x][y] = distance[index.x][index.y]+1;
					continue;
				}
				exp--;
				if(exp <= 0)
					exp = ++sharkSize;
				field[x][y] = 0;
				time += distance[index.x][index.y]+1;
				return new Position(x, y);
			}
		}
		return new Position(-1, -1);
	}
}
class Position{
	int x, y;
	public Position(int x, int y) {
		this.x = x;
		this.y = y;
	}
}
