public class ListByUsingLinkedList {
	private static class Entry {
		int    key;
		Object data;
		Entry  next;

		private Entry(int key, Object data) {
			this.key  = key;
			this.data = data;
			this.next = null;
		}
	}

	Entry head = null;
	int numOfEntry = 0;

	// データ登録
	public void add(int key, Object data) {
		if (numOfEntry == 0) {
			head = new Entry(key, data);
		} else {
			Entry p = head;
			for (; p.next != null; p = p.next);
			p.next = new Entry(key, data);
		}
		numOfEntry++;
	}

	public Object search(int key) {
		Entry p = head;
		while (p != null) {
			if (key == p.key) {
				return p.data;
			}
			p = p.next;
		}
		return null;
	}

	public static void main(String[] args) {
		ListByUsingLinkedList list = new ListByUsingLinkedList();
		list.add(0, "A");
		list.add(1, "B");
		list.add(2, "C");
		list.add(3, "D");

		int key = 2;
		System.out.println(key + ", " + list.search(key));
	}
}
