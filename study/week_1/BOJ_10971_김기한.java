import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
	private static int path[];
	private static int weigh[][];
	private static int n;
	private static int min = Integer.MAX_VALUE;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		n = Integer.parseInt(br.readLine());
		path = new int[n];
		weigh = new int[n][n];
		for(int i=0; i<n; i++) {
			path[i] = i;
		}
		String[] input;
		for(int i=0; i<n; i++) {
			input = br.readLine().split(" ");
			for(int j=0; j<n; j++) {
				weigh[i][j] = Integer.parseInt(input[j]);
			}
		}
		run();
		bw.write(String.valueOf(min));
		
		bw.flush();
		bw.close();
	}
	public static void run() {
		while(true) {
			int sum = 0;
			for(int i=0; i<n-1; i++) {
				sum += weigh[path[i]][path[i+1]];
				if(weigh[path[i]][path[i+1]] == 0) {
					sum = Integer.MAX_VALUE;
					break;
				}
			}
			if(sum != Integer.MAX_VALUE && weigh[path[n-1]][path[0]] != 0) sum += weigh[path[n-1]][path[0]];
			if(weigh[path[n-1]][path[0]] == 0) sum = Integer.MAX_VALUE;
			if(sum < min) min = sum;
			
			int i = n-1;
			int j = n-1;
			while(i > 0 && path[i-1] > path[i]) i--;
			if(i == 0) break;
			while(path[i-1] > path[j]) j--;
			swap(i-1, j);
			Arrays.sort(path, i, n);
		}
	}
	public static void swap(int i, int j) {
		int temp = path[i];
		path[i] = path[j];
		path[j] = temp;
	}
}