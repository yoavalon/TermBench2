public class sample_2119 {
    public static void track_sequence() {
        double a = 0.0;
        double b = 1.0;
        while (true) {
            double c = a + b;
            a = b;
            b = c;
            System.out.println(c);
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}