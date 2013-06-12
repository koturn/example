public class KecsSmartCard {
	int    deposit;
	int    roomNumber;
	String name;

	public KecsSmartCard() {
		this.deposit    = 0;
		this.roomNumber = -1000;
		this.name       = "no name";
	}

	public KecsSmartCard(int deposite) {
		this.deposit    = deposite;
		this.roomNumber = -2000;
		this.name       = "????";
	}


	public void setProfile(int roomNumber) {
		this.roomNumber = roomNumber;
	}

	public void setProfile(String name) {
		this.name = name;
	}

	public void setProfile(int roomNumber, String name) {
		this.roomNumber = roomNumber;
		this.name       = name;
	}

	public void makeDeposit(int deposit) {
		this.deposit += deposit;
	}

	public int drawDeposit(int deposit) {
		this.deposit -= deposit;
		return deposit;
	}

	public void printDeposit() {
		System.out.println(this.name + " san's deposit = " + this.deposit);
		System.out.println("Room Number = " + this.roomNumber);
		System.out.println("---");
	}
}
