public class sample_2177 {
    public static void track_sequence() {
        double a = 0.0, b = 1.0;
        while (true) {
            double c = a + b;
            a = b;
            b = c;
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}