public class ListByUsingArray {
	private static class Entry {
		int    key;
		Object data;

		private Entry(int key, Object data) {
			this.key  = key;
			this.data = data;
		}
	}

	final static int MAX = 5;
	Entry[] table  = new Entry[MAX];
	int numOfEntry = 0;

	// データ登録
	public void add(int key, Object data) {
		table[numOfEntry++] = new Entry(key, data);
	}

	public Object search(int key) {
		int i = 0;
		while (i < numOfEntry) {
			if (key == table[i].key) {
				return table[i].data;
			}
			i++;
		}
		return null;
	}

	public static void main(String[] args) {
		ListByUsingArray list = new ListByUsingArray();
		list.add(0, "A");
		list.add(1, "B");
		list.add(2, "C");
		list.add(3, "D");

		int key = 2;
		System.out.println(key + ", " + list.search(key));
	}
}
