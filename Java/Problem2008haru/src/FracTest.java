public class FracTest {
	public static void main(String[] args) {
		Fraction f1, f2;
		MixedFraction mf;
		System.out.println("これは分数計算のテストプログラムです");
		f1 = new Fraction(2, 5);
		mf = new MixedFraction(10, new Fraction(3, 7));
		f2 = mf.toFrac();
		System.out.print("変換後の分子は ");
		System.out.println(f2.getNum());
		System.out.print("変換後の分数の分母は ");
		System.out.println(f2.getDen());
	}
}
