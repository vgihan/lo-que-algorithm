import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class Main {
	private static int dx[] = new int[] {-1, -1, 0, 1, 1, 1, 0, -1};
	private static int dy[] = new int[] {0, 1, 1, 1, 0, -1, -1, -1};
	private static int n, m;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		
		String input[];
		int count;
		
		while(true) {
			input = br.readLine().split(" ");
			count = 0;
			n = Integer.parseInt(input[0]);
			m = Integer.parseInt(input[1]);
			
			if(n == 0 && m == 0) break;
			
			int field[][] = new int[m][n];
			for(int i=0; i<m; i++) {
				input = br.readLine().split(" ");
				for(int j=0; j<n; j++) {
					field[i][j] = Integer.parseInt(input[j]);
				}
			}
			for(int i=0; i<m; i++) {
				for(int j=0; j<n; j++) {
					if(field[i][j] == 1) {
						count++;
						dfs(i, j, field);
					}
				}
			}
			bw.write(String.valueOf(count)+"\n");
		}
		bw.flush();
		bw.close();
	}
	public static void dfs(int x, int y, int field[][]) {
		field[x][y] = 0;
		int nx, ny;
		for(int i=0; i<8; i++) {
			nx = x+dx[i];
			ny = y+dy[i];
			if(nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] == 1) {
				dfs(nx, ny, field);
			}
		}
	}
}