import java.io.*;

public class Separate {
	public static void main(String[] args) throws IOException {
		int n;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("正の整数を入力してください");
		n = Integer.parseInt(in.readLine());

		int digitArray[] = new int[1024];
		int idx = 0;
		while (n != 0) {
			digitArray[idx++] = n % 10;
			n /= 10;
		}

		for (int i = 0; i < idx; i++) {
			System.out.print(digitArray[i] + " ");
		}
		System.out.println();
		for (int i = idx - 1; i >= 0; i--) {
			System.out.print(digitArray[i] + " ");
		}
	}
}
