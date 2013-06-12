public class KecsWorld {
	public static void main(String[] args) {
		String name1 = "Taro";
		String name2 = "Hanako";
		int roomNumber1 = 123;
		int roomNumber2 = 303;
		int money;

		KecsSmartCard Card1 = new KecsSmartCard();
		Card1.printDeposit();

		KecsSmartCard Card2 = new KecsSmartCard(5000);
		Card2.printDeposit();

		Card1.setProfile(name1);
		Card1.printDeposit();
		Card1.setProfile(roomNumber1);
		Card1.printDeposit();
		Card1.makeDeposit(3500);
		Card1.printDeposit();
		money = Card1.drawDeposit(1500);
		System.out.println("I got " + money + "!");
		System.out.println();
		Card1.printDeposit();

		Card2.setProfile(roomNumber2, name2);
		Card2.printDeposit();
		money = Card2.drawDeposit(6500);
		System.out.println("I got " + money + "!");
		System.out.println();
	}
}
