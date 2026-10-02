public class sample_0100 {
    public static int calculate_cruise_altitude() {
        int a = 34000, b = 36000, c = 38000;
        while (true) {
            if (a < b && b < c) {
                return b;
            }
            a = b;
            b = c;
            c = c + 2000;
        }
    }

    public static void main(String[] args) {
        calculate_cruise_altitude();
    }
}