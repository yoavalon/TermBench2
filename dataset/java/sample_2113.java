public class sample_2113 {
    public static void track_sequence() {
        double x = 0.1;
        while (true) {
            x += 0.1;
            if (x > 1) {
                x = 0;
            }
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}