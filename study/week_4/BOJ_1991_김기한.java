import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	private static List<Integer> list[];
	private static int n;
	public static void main(String[] args) throws NumberFormatException, IOException {
		n = Integer.parseInt(br.readLine());
		list = new ArrayList[26];
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int curNode = toInteger(st.nextToken().toCharArray()[0]);
			int leftNode = toInteger(st.nextToken().toCharArray()[0]);
			int rightNode = toInteger(st.nextToken().toCharArray()[0]);
			list[curNode] = new ArrayList<>();
			list[curNode].add(leftNode);
			list[curNode].add(rightNode);
		}
		preorder(0);
		bw.write("\n");
		inorder(0);
		bw.write("\n");
		postorder(0);
		
		bw.flush();
		bw.close();
	}
	public static void preorder(int index) throws IOException {
		int leftNode = list[index].get(0);
		int rightNode = list[index].get(1);
		bw.write(toCharacter(index));
		if(leftNode != toInteger('.')) {
			preorder(leftNode);
		}
		if(rightNode != toInteger('.')) {
			preorder(rightNode);
		}
	}
	public static void inorder(int index) throws IOException {
		int leftNode = list[index].get(0);
		int rightNode = list[index].get(1);
		if(leftNode != toInteger('.')) {
			inorder(leftNode);
		}
		bw.write(toCharacter(index));
		if(rightNode != toInteger('.')) {
			inorder(rightNode);
		}
	}
	public static void postorder(int index) throws IOException {
		int leftNode = list[index].get(0);
		int rightNode = list[index].get(1);
		if(leftNode != toInteger('.')) {
			postorder(leftNode);
		}
		if(rightNode != toInteger('.')) {
			postorder(rightNode);
		}
		bw.write(toCharacter(index));
	}
	public static int toInteger(char character) {
		return character-65;
	}
	public static char toCharacter(int Integer) {
		return (char) (Integer+65);
	}
}
