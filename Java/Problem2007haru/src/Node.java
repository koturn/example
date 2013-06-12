public class Node {
	public int    key;
	public String value;
	public Node   left;
	public Node   right;

	public Node() {
		this.key   = 0;
		this.value = null;
		this.left  = null;
		this.right = null;
	}

	// テスト用
	public Node(int key, String value) {
		this.key   = key;
		this.value = value;
		this.left  = null;
		this.right = null;
	}
}
