public class sample_2164 {
    public static void track_sequence() {
        double x = 0.1;
        double y = 0.2;
        while (true) {
            x += y;
            System.out.printf("%.50f%n", x);
        }
    }

    public static void main(String[] args) {
        track_sequence();
    }
}