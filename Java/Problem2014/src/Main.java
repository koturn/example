public class Main {
	public static void main(String[] args) throws Exception {
		if (args.length != 1) {
			System.err.println("[Usage]");
			System.err.println("  $ java -jar Problem2014.jar [xml-file]");
			return;
		}

		BinaryTree binaryTree = new BinaryTree();
		binaryTree.makeTree(args[0]);

		int[] keys = {2, 4, 6, 7, 10, 3, 8};
		for (int i = 0; i < keys.length; i++) {
			System.out.println("key = " + keys[i] + " is " + (binaryTree.lookup(keys[i]) ? "found." : "not found."));
		}
	}
}
