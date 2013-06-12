import java.io.*;

public class Kakutani {
	public static void main(String[] args) throws IOException {
		int n;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("正の整数を入力してください");
		n = Integer.parseInt(in.readLine());

		int cnt = 0;
		for (; n != 1; cnt++) {
			System.out.println(" " + cnt + "      " + n);
			if (n % 2 == 0) {
				n /= 2;
			} else {
				n = 3 * n + 1;
			}
		}
		System.out.println(" " + cnt + "      " + n);
		System.out.println("end");
	}
}
