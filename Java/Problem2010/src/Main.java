public class Main {
	public static void main(String[] args) {
		String in = "abc";
		System.out.println(in);
		Reverser reverser = new Reverser(in);

		String out = reverser.do_reverse();
		System.out.println(out);
	}
}
