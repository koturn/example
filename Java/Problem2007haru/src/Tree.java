public class Tree {
	public Node top;

	public Node search(int key) {
		Node node = top;
		while (node != null) {
			if (node.key == key) {
				return node;
			} else if (key < node.key) {
				node = node.left;
			} else if (node.key < key) {
				node = node.right;
			}
		}
		return null;
	}
}
