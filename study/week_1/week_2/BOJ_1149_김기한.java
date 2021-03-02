import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static int n;
	private static int field[][];
	public static void main(String[] args) throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		field = new int[n][3];
		StringTokenizer st;
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			field[i][0] = Integer.parseInt(st.nextToken());
			field[i][1] = Integer.parseInt(st.nextToken());
			field[i][2] = Integer.parseInt(st.nextToken());
		}
		bw.write(String.valueOf(solution()));
		
		bw.flush();
		bw.close();
	}
	public static int solution() {
		int dp[][] = new int[n][3];
		for(int i=0; i<3; i++) {
			dp[0][i] = field[0][i];
		}
		for(int i=1; i<n; i++) {
			dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + field[i][0];
			dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + field[i][1];
			dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + field[i][2];
		}
		return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
	}
	public static int min(int a, int b) {
		return a < b ? a : b;
	}
}
