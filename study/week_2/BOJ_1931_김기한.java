import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static int n;
	private static meeting field[];
	private static int count = 0;
	private static int index = -1;
	public static void main(String args[]) throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		field = new meeting[n];
		StringTokenizer st;
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			int start = Integer.parseInt(st.nextToken());
			int end = Integer.parseInt(st.nextToken());
			field[i] = new meeting(start, end);
		}
		Arrays.sort(field);
		solution();
		bw.write(String.valueOf(count));
		
		bw.flush();
		bw.close();
		br.close();
	}
	public static void solution() {
		for(int i=0; i<n; i++) {
			if(field[i].start >= index) {
				count++;
				index = field[i].end;
			}
		}
	}
}
class meeting implements Comparable<meeting>{
	int start;
	int end;
	public meeting(int start, int end) {
		this.start = start;
		this.end = end;
	}
	@Override
	public int compareTo(meeting o) {
		if(this.end > o.end) return 1;
		else if(this.end < o.end) return -1;
		else {
			if(this.start > o.start) return 1;
			else return -1;
		}
	}
	
}
