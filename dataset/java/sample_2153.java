public class sample_2153 {
    public static void flight_trajectory() {
        double a = 1.0, b = 0.0, c = 0.0;
        while (true) {
            c = a + b;
            a = b;
            b = c;
            System.out.println(c);
        }
    }

    public static void main(String[] args) {
        flight_trajectory();
    }
}