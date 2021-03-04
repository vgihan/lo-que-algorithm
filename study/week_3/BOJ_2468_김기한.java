import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static int dx[] = {1, 0, -1, 0};
	private static int dy[] = {0, -1, 0, 1};
	private static int field[][];
	private static boolean check[][];
	private static int n;
	private static int max, min;
	private static int result = 1;
	public static void main(String[] args) throws NumberFormatException, IOException {
		max = 1;
		min = 100;
		n = Integer.parseInt(br.readLine());
		field = new int[n][n];
		check = new boolean[n][n];
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());	
			for(int j=0; j<n; j++) {
				field[i][j] = Integer.parseInt(st.nextToken());
				if(max < field[i][j]) max = field[i][j];
				if(min > field[i][j]) min = field[i][j];
			}
		}
		solution();
		bw.write(String.valueOf(result));
		
		bw.flush();
		bw.close();
	}
	public static void solution() {
		for(int h=min; h<max; h++) {
			int count = 0;
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					check[i][j] = false;
					if(field[i][j] <= h) {
						check[i][j] = true;
					}
				}
			}
			for(int i=0; i<n; i++) {
				for(int j=0; j<n; j++) {
					if(!check[i][j]) {
						dfs(i, j);
						count++;
					}
				}
			}
			if(count > result) result = count;
		}
	}
	public static void dfs(int x, int y) {
		check[x][y] = true;
		for(int i=0; i<4; i++) {
			if(x+dy[i] >= 0 && y+dx[i] >= 0	&& x+dy[i] < n && y+dx[i] < n
					&& !check[x + dy[i]][y + dx[i]]) {
				dfs(x + dy[i], y + dx[i]);
			}
		}
	}
}
