import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static int n, p;
	private static int field[][];
	private static Stack<Guitar> stack[];
	private static int count = 0;
	public static void main(String[] args) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		p = Integer.parseInt(st.nextToken());
		field = new int[n][2];
		stack = new Stack[7];
		for(int i=1; i<7; i++) {
			stack[i] = new Stack<>();
		}
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			field[i][0] = Integer.parseInt(st.nextToken());
			field[i][1] = Integer.parseInt(st.nextToken());
		}
		solution();
		bw.write(String.valueOf(count));
		
		bw.flush();
		bw.close();
	}
	public static void solution() {
		for(int i=0; i<n; i++) {
			int line = field[i][0];
			int fret = field[i][1];
			Guitar curMelody = new Guitar(line, fret);
			while(!stack[line].empty() && stack[line].peek().fret > fret) {
				stack[line].pop();
				count++;
			}
			if(!stack[line].empty() 
					&& curMelody.line == stack[line].peek().line 
					&& curMelody.fret == stack[line].peek().fret) {
				continue;
			}
			count++;
			stack[line].push(curMelody);
		}
	}
}
class Guitar{
	int line, fret;
	public Guitar(int line, int fret) {
		this.line = line;
		this.fret = fret;
	}
}
