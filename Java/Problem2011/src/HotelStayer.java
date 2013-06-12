public class HotelStayer {
	public static void main(String[] args) {
		// ホテルの宿泊客の人数の配列
		int[][] hotelRoom = new int[][] {
				{1, 2, 0, 3, 1, 2, 1, 1, 0, 2, 1, 1, 0, 0, 2, 3},
				{3, 2, 1, 0, 3, 2, 1, 0, 3, 2, 1, 0, 3, 2, 1, 0},
				{2, 2, 2, 2, 1, 1, 1, 1, 3, 3, 3, 3, 3, 2, 2, 2}
		};

		// (1) ここに総宿泊者数を表示するプログラムを記述する
		int sum = 0;
		int i   = -1;
		while (++i < hotelRoom.length) {
			int j = -1;
			while (++j < hotelRoom[i].length) {
				sum += hotelRoom[i][j];
			}
		}
		System.out.println("総宿泊客数：" + sum + "人");
		System.out.println();


		// (2) ここに各部屋の宿泊客の数を指定の形式で表示するプログラムを記述する
		i = -1;
		while (++i < hotelRoom.length) {
			int j = -1;
			while (++j < hotelRoom[i].length) {
				System.out.printf("%d%02d号室：", i + 1, j + 1);
				if (hotelRoom[i][j] == 0) {
					System.out.println("空室");
				} else {
					System.out.println(hotelRoom[i][j] + "人");
				}
			}
		}
	}
}
