public class Main {
    public static void main(String[] args) {
		Node top       = new Node(10, "top");
		top.left       = new Node(5,  "top-left");
		top.left.left  = new Node(2,  "top-left-left");
		top.left.right = new Node(4,  "top-left-right");

		top.right       = new Node(15, "top-right");
		top.right.left  = new Node(12, "top-right-left");
		top.right.right = new Node(18, "top-right-right");

		Tree tree = new Tree();
		tree.top  = top;

		Node ret = tree.search(13);
		if (ret == null) {
			System.out.println("Not found.");
		} else {
			System.out.println(ret.value);
		}
    }
}
