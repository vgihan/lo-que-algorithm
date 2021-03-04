import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static int n, m;
	private static int field[][];
	private static int dp[][];
	private static int max = 0;
	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		field = new int[n+1][m+1];
		dp = new int[n+1][m+1];
		for(int i=1; i<=n; i++) {
			String tmp[] = br.readLine().split("");
			for(int j=1; j<=m; j++) {
				field[i][j] = Integer.parseInt(tmp[j-1]);
			}
		}
		solution();
		bw.write(String.valueOf(max*max));
		
		bw.flush();
		bw.close();
	}
	public static void solution() {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(field[i][j] == 0) {
					dp[i][j] = 0;
					continue;
				}
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
				if(dp[i][j] == 0) dp[i][j] = 1;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(max < dp[i][j]) max = dp[i][j];
			}
		}
	}
	public static int min(int a, int b, int c) {
		if(a <= b && a <= c) return a;
		else if(b <= a && b <= c) return b;
		else if(c <= b && c <= a) return c;
		else return 0;
	}
}
