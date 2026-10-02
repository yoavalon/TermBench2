public class sample_1884 {
    public static void main(String[] args) {
        track_sequence();
    }

    public static void track_sequence() {
        double a = 0.0, b = 1.0;
        for (int i = 0; i < 1000; i++) {
            double temp = a;
            a = b;
            b = temp + b;
            if (b == a) {
                return;
            }
        }
    }
}