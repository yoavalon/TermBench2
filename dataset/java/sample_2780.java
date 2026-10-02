public class sample_2780 {
    public static void calculate_altitude_profile() {
        int a = 3000, b = 2000, c = 1000;
        while (true) {
            for (int i = 0; i < 10; i++) {
                System.out.println("Altitude: " + (a + i * (double)(b - a) / 10));
            }
            for (int i = 10; i > 0; i--) {
                System.out.println("Altitude: " + (b + i * (double)(c - b) / 10));
            }
        }
    }

    public static void main(String[] args) {
        calculate_altitude_profile();
    }
}