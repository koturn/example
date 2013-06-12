import java.io.*;


public class BinarySearchExample {
	public static void main(String args[]) {
		int key = 77;
		int num[] = {14, 24, 35, 46, 52, 63, 77, 89, 91, 100};
		binarySearch(num, 0, 9, key);
	}

	public static void binarySearch(int array[], int lowerbound, int upperbound, int key) {
		int position;
		int comparisonCount = 1;

		position = (lowerbound + upperbound) / 2;
		while ((array[position] != key) && (lowerbound <= upperbound)) {
			System.out.println("comparisonCount = " + comparisonCount
					+ ", lowerbound = " + lowerbound
					+ ", upperbound = " + upperbound
					+ ", position = "   + position
			);
			if (array[position] > key) {
				upperbound = position - 1;
			} else {
				lowerbound = position + 1;
			}
			position = (lowerbound + upperbound) / 2;
			comparisonCount++;
		}

		if (lowerbound <= upperbound) {
			System.out.println("comparisonCount = " + comparisonCount
					+ ", lowerbound = " + lowerbound
					+ ", upperbound = " + upperbound
					+ ", position = "   + position
			);
			System.out.println("--------------------------------------------------------------------------------");
			System.out.println("The number was found in array subscript " + position);
			System.out.println("The binary search found the number after " + comparisonCount + " comparisons.");
		} else {
			System.out.println("Sorry, the number is not in thos array. The binary search made " + comparisonCount + "comparisons.");
		}
	}
}
