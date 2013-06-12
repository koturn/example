class Reverser {
	private String input;   // 入力された文字列
	private String output;  // 反転した文字列

	public Reverser(String in) {
		input = in;
	}
	public String do_reverse() {
		StackX sx = new StackX(input.length());
		for (int i = 0; i < input.length(); i++) {
			char c = input.charAt(i);
			sx.push(c);
		}

		String str = "";
		while (!sx.isEmpty()) {
			str += sx.pop();
		}

		return str;
	}
}
