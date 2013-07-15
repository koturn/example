import java.io.FileInputStream;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;


public class BinaryTree {
	private Node root;
	private static class Node {
		Node left;
		Node right;
		int  data;
	}

	public boolean lookup(int data) {
		return lookup(root, data);
	}

	private boolean lookup(Node node, int data) {
		if (node == root) {
			return lookup(node.left, data);
		} else if (node == null) {
			return false;
		} else if (node.data == data) {
			return true;
		} else if (node.data > data) {
			return lookup(node.left, data);
		} else {
			return lookup(node.right, data);
		}
	}


	/* ========== for test ========== */
	public void makeTree(String xmlFileName) throws Exception {
		DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
		DocumentBuilder db = dbf.newDocumentBuilder();
		Document doc = db.parse(new FileInputStream(xmlFileName));;
		Element xmlRoot = doc.getDocumentElement();

		root = new Node();
		walk(xmlRoot, root);
	}

	private void walk(org.w3c.dom.Node xmlNode, Node node) throws Exception {
		for (org.w3c.dom.Node child = xmlNode.getFirstChild(); child != null; child = child.getNextSibling()) {
			String nodeName = child.getNodeName();
			if (nodeName.equals("value")) {
				node.data = Integer.parseInt(child.getTextContent());
			} else if (nodeName.equals("left")) {
				node.left = new Node();
				walk(child, node.left);
			} else if (nodeName.equals("right")) {
				node.right = new Node();
				walk(child, node.right);
			} else if (!nodeName.equals("#text")){
				throw new Exception();
			}
		}
	}
}
