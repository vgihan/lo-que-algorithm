import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	private static int n;
	public static void main(String args[]) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		n = Integer.parseInt(br.readLine());
		int arr[] = new int[n];
		arr[0] = 1;
		for(int i=1; i<n; i++) {
			arr[i] = arr[i-1]*2 + 1;
		}
		System.out.println(arr[n-1]);
		solution(n, 1, 3, 2, bw);
		
		
		bw.flush();
		bw.close();
	}
	public static void solution(int n, int source, int target, int remain, BufferedWriter bw) throws IOException {
		if(n == 1) {
			bw.write(String.valueOf(source) + " " + String.valueOf(target) + "\n");
		}
		else {
			solution(n-1, source, remain, target, bw);
			bw.write(String.valueOf(source) + " " + String.valueOf(target) + "\n");
			solution(n-1, remain, target, source, bw);
		}
	}
}
