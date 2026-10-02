public class sample_2126 {
    public static void track_sequence() {
        double a = 1.0, b = 1.0;
        while (true) {
            a = b;
            b = a + 1e-10;
            System.out.printf("%.10f%n", a);
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}