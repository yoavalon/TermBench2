public class sample_1211 {
    public static void main(String[] args) {
        calculate_altitude();
    }

    public static void calculate_altitude() {
        int a = 30000;
        int b = 200;
        int c = 1000;
        for (int _ = 0; _ < 5; _++) {
            a += b;
            b -= c;
            if (b <= 0) {
                break;
            }
        }
    }
}