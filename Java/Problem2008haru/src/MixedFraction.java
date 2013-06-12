public class MixedFraction {
	private int      intPart;
	private Fraction fracPart;

	public MixedFraction(int intPart, Fraction fracPart) {
		this.intPart  = intPart;
		this.fracPart = fracPart;
	}

	public Fraction toFrac() {
		return new Fraction(fracPart.getNum() + intPart * fracPart.getDen(), fracPart.getDen());
	}
}
