import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static int n;
	private static int field[][];
	private static int ace[];
	private static int permutation[];
	private static int curOrder[][];
	private static int max = 0;
	public static void main(String args[]) throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		field = new int[n][8];
		curOrder = new int[n][9];
		permutation = new int[8];
		ace = new int[n];
		for(int i=0; i<8; i++) {
			permutation[i] = i;
		}
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<9; j++) {
				if(j == 0) {
					ace[i] = Integer.parseInt(st.nextToken());
					continue;
				}
				field[i][j-1] = Integer.parseInt(st.nextToken());
			}
		}
		solution();
		bw.write(String.valueOf(max));
		
		bw.flush();
		bw.close();
	}
	public static void solution() {
		do {
			makeOrder();
			calScore();
		}while(nextPermutation(permutation, 8));
	}
	public static void calScore() {
		int inning = 0;
		int index = 0;
		int outCount = 0;
		int sum = 0;
		Queue<Integer> queue = new LinkedList<>();
		while(inning < n) {
			clearField(queue);
			while(outCount < 3) {
				if(curOrder[inning][index] == 0) {
					outCount++;
					index++;
					index %= 9;
					continue;
				}
				queue.add(1);
				sum += queue.poll();
				for(int i=0; i<curOrder[inning][index]-1; i++) {
					queue.add(0);
					sum += queue.poll();					
				}
				index++;
				index %= 9;
			}
			outCount = 0;
			inning++;
		}
		if(max < sum) {
			max = sum;
		}
	}
	public static void clearField(Queue<Integer> queue) {
		queue.clear();
		for(int i=0; i<3; i++) {
			queue.add(0);
		}
	}
	public static void makeOrder() {
		for(int i=0; i<n; i++) {
			for(int j=0; j<9; j++) {
				if(j == 3) curOrder[i][j] = ace[i];
				else if(j < 3) curOrder[i][j] = field[i][permutation[j]];
				else if(j > 3) curOrder[i][j] = field[i][permutation[j-1]];
			}
		}
	}
	public static boolean nextPermutation(int arr[], int size) {
		int i = size-1;
		while(i > 0 && arr[i-1] >= arr[i]) i--;
		if(i <= 0) return false;
		int j = size-1;
		while(arr[i-1] >= arr[j]) j--;
		swap(arr, i-1, j);
		Arrays.sort(arr, i, size);
		return true;
	}
	public static void swap(int arr[], int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
